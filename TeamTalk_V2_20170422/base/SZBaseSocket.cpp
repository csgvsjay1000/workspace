#include "SZBaseSocket.h"
#include "SZEventDispatch.h"
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <google/protobuf/message_lite.h>
#include "pb/IM.Server.pb.h"

using namespace std;

typedef hash_map<int,SZBaseSocket*> SZSocketMap;
SZSocketMap g_socket_map;

SZBaseSocket* FindBaseSocket(int fd)
{
	SZBaseSocket* pSocket = NULL;
	SZSocketMap::iterator it = g_socket_map.find(fd);
	if(it != g_socket_map.end())
	{
		pSocket = it->second;
	}
	return pSocket;
}

void AddBaseSocket(SZBaseSocket* pSocket)
{
	g_socket_map.insert(make_pair(pSocket->GetSocket(),pSocket));
}

void RemoveBaseSocket(SZBaseSocket* pSocket)
{
	g_socket_map.erase(pSocket->GetSocket());
}

int SZBaseSocket::Listen(const char* ip,uint16_t port,callback_t callback)
{
	m_callback = callback;
	int socket = ::socket(AF_INET,SOCK_STREAM,0);
	_SetReuseAddr(socket);
	_SetNonblock(socket);
	sockaddr_in serv_addr;
	_SetAddr(ip,port,&serv_addr);

	::bind(socket,(sockaddr*)&serv_addr,sizeof(serv_addr));
	::listen(socket,64);
	printf("SZBaseSocket::Listen on %s:%d\n",ip,port);
	m_socket = socket;
	AddBaseSocket(this);
	SZEventDispatch::Instance()->AddEvent(socket);
	m_state = SZSOCKET_STATE_LISTENNING;
	return socket;
}

int SZBaseSocket::Connect(const char* ip,uint16_t port,callback_t callback)
{
	m_callback = callback;
	int socket = ::socket(AF_INET,SOCK_STREAM,0);
	//_SetReuseAddr(socket);
	_SetNonblock(socket);
	sockaddr_in serv_addr;
	_SetAddr(ip,port,&serv_addr);
	socklen_t addr_len = sizeof(serv_addr);
	int ret = ::connect(socket,(sockaddr*)&serv_addr,addr_len);
	if(ret == -1 && (!_IsBlock(errno)))
	{
		printf("SZBaseSocket::Connect err_code=%d\n",errno);
		return -1;
	}
	printf("SZBaseSocket::Connect on socket=%d\n",socket);
	m_socket = socket;
	AddBaseSocket(this);
	SZEventDispatch::Instance()->AddEvent(socket);
	m_state = SZSOCKET_STATE_CONNECTING;
	return socket;
}
void SZBaseSocket::_SetReuseAddr(int fd)
{
	int reuse = 1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,(char*)&reuse,sizeof(reuse));
}
void SZBaseSocket::_SetAddr(const char* ip,uint16_t port,sockaddr_in* pAddr)
{
	memset(pAddr,0,sizeof(sockaddr_in));
	pAddr->sin_family = AF_INET;
	pAddr->sin_port = htons(port);
	pAddr->sin_addr.s_addr = inet_addr(ip);
}

int SZBaseSocket::AcceptNewSocket()
{
	int fd = 0;
	sockaddr_in peer_addr;
	socklen_t add_len = sizeof(sockaddr_in);
	char ip_str[64];
	while((fd = ::accept(m_socket,(sockaddr*)&peer_addr,&add_len)) != -1)
	{
		uint32_t ip = ntohl(peer_addr.sin_addr.s_addr);
		uint16_t port = ntohs(peer_addr.sin_port);

		snprintf(ip_str,sizeof(ip_str),"%d.%d.%d.%d",ip>>24,(ip>>16)&0xFF,(ip>>8)&0xFF,ip&0xFF);
		printf("AcceptNewSocket, socket=%d from %s:%d\n",fd,ip_str,port);
		SZBaseSocket* pSocket = (SZBaseSocket*)m_callback(NULL);
		pSocket->SetSocket(fd);
		pSocket->SetState(SZSOCKET_STATE_CONNECTED);
		AddBaseSocket(pSocket);
		_SetNonblock(fd);
		SZEventDispatch::Instance()->AddEvent(fd);
	}
	return 0;
}
void SZBaseSocket::OnRead()
{
	if(m_state == SZSOCKET_STATE_LISTENNING)
	{
		AcceptNewSocket();
	}
	else if(m_state == SZSOCKET_STATE_CONNECTED)
	{
		u_long avail = 0;
		int ret = ioctl(m_socket,FIONREAD,&avail);
		if(ret == -1 || avail == 0)
		{
			printf("close socket=%d\n",m_socket);
			OnClose();
		}
		else
		{
			ReadPacket();
		}
	}
	else
	{

	}
}
void SZBaseSocket::OnWrite()
{
	printf("socket=%d, OnWrite\n",m_socket);
	if(m_state == SZSOCKET_STATE_CONNECTING)
	{
		m_state = SZSOCKET_STATE_CONNECTED;
		m_callback(this);
	}
}


void SZBaseSocket::ReadPacket()
{
	for(;;){
		uint32_t free_buf_len = m_simpleInBuffer.GetAllocSize() - m_simpleInBuffer.GetWriteOffset();
		if(free_buf_len < 2048)
			m_simpleInBuffer.Extend(2048);
		int ret = ::recv(m_socket,m_simpleInBuffer.GetBuffer()+m_simpleInBuffer.GetWriteOffset(),2048,0);
		if(ret <= 0)
			break;
		m_simpleInBuffer.IncWriteOffset(ret);

	}
	SZPduBase *pPdu = NULL;
	pPdu = SZPduBase::ReadPdu(m_simpleInBuffer.GetBuffer(),m_simpleInBuffer.GetWriteOffset());
	//printf("offset:%5d length:%5d : %s\n",m_simpleInBuffer.GetWriteOffset(),pPdu->GetLength(),pPdu->GetBodyData());	
	HandlePdu(pPdu);

	m_simpleInBuffer.Read(NULL,pPdu->GetLength());
	delete pPdu;
	pPdu = NULL;

}
void SZBaseSocket::OnClose()
{
	SZEventDispatch::Instance()->RemoveEvent(m_socket);
	RemoveBaseSocket(this);
	close(m_socket);

}

void SZBaseSocket::_SetNonblock(int fd)
{
	fcntl(fd,F_SETFL,O_NONBLOCK|fcntl(fd,F_GETFL));	
}

void SZBaseSocket::Send(void* buf,int len)
{
	::send(m_socket,(char*)buf,len,0);
}
void SZBaseSocket::Recv(void* buf,int len)
{
	::recv(m_socket,(char*)buf,len,0);
}

bool SZBaseSocket::_IsBlock(int err_code)
{
	return (err_code==EINPROGRESS) || (err_code == EWOULDBLOCK);
}

