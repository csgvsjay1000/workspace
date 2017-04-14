#include "BaseSocket.h"
#include <errno.h>
#include <fcntl.h>
#include "EventDispatch.h"
#include <termios.h>
#include <sys/ioctl.h>

typedef hash_map<int,CBaseSocket*> SocketMap;
SocketMap g_socket_map;

void AddBaseSocket(CBaseSocket* pSocket)
{
	g_socket_map.insert(make_pair(pSocket->GetSocket(),pSocket));
}

void RemoveBaseSocket(CBaseSocket* pSocket)
{
	g_socket_map.erase(pSocket->GetSocket());
}

CBaseSocket* FindBaseSocket(int fd)
{
	CBaseSocket* pSocket = NULL;
	SocketMap::iterator it = g_socket_map.find(fd);
	if(it != g_socket_map.end())
	{
		pSocket = it->second;
		pSocket->AddRef();
	}
	return pSocket;
}

CBaseSocket::CBaseSocket()
{
	m_socket = -1;
	m_state = SOCKET_STATE_IDLE;
}

int CBaseSocket::Listen(const char* ip,uint16_t port,callback_t callback,void* callback_data)
{
	m_socket = socket(AF_INET,SOCK_STREAM,0);
	if(m_socket == -1)
	{
		log("socket failed,err_code=%d",errno);
		return -1;
	}	
	_SetReuseAddr(m_socket);
	_SetNonblock(m_socket);

	sockaddr_in serv_addr;
	_SetAddr(ip,port,&serv_addr);
	int ret = ::bind(m_socket,(sockaddr*)&serv_addr,sizeof(serv_addr));
	if(ret == -1)
	{
		log("bind failed,err_code=%d",errno);
		close(m_socket);
		return -1;
	}
	ret = listen(m_socket,64);
	if(ret == -1)
	{
		log("listen failed,err_code=%d",errno);
		close(m_socket);
		return -1;
	}
	m_state = SOCKET_STATE_LISTENING;

	loginfo("CBaseSocket::Listen on %s:%d",ip,port);
	AddBaseSocket(this);
	CEventDispatch::Instance()->AddEvent(m_socket);
	return 0;
}

void CBaseSocket::OnRead()
{
	if(m_state == SOCKET_STATE_LISTENING)
	{
		_AcceptNewSocket();
	}else{
		u_long avail = 0;
		if(ioctl(m_socket,FIONREAD,&avail)==-1 || avail==0){
			m_callback(m_callbackData,NETLIB_MSG_CLOSE,(uint32_t)m_socket,NULL);
		}else{
			m_callback(m_callbackData,NETLIB_MSG_READ,(uint32_t)m_socket,NULL);
		}
	}
}

void CBaseSocket::OnWrite()
{
	if(m_state == SOCKET_STATE_CONNECTING)
	{
		int error = 0;
		socklen_t len = sizeof(error);
		getsockopt(m_socket,SOL_SOCKET,SO_ERROR,(void*)&error,&len);
		if(error){
			m_callback(m_callbackData,NETLIB_MSG_CLOSE,(uint32_t)m_socket,NULL);
		}else{
			m_state = SOCKET_STATE_CONNECTED;
			m_callback(m_callbackData,NETLIB_MSG_CONFIRM,(uint32_t)m_socket,NULL);
		}
	}else{
		m_callback(m_callbackData,NETLIB_MSG_WRITE,(uint32_t)m_socket,NULL);
	}
}

void CBaseSocket::OnClose()
{
	m_state = SOCKET_STATE_CLOSING;
	m_callback(m_callbackData,NETLIB_MSG_CLOSE,m_socket,NULL);
}

int CBaseSocket::Send(void* buf,int len)
{
	return send(m_socket,(char*)buf,len,0);
}

int CBaseSocket::Recv(void* buf,int len)
{
	return recv(m_socket,(char*)buf,len,0);	
}

int CBaseSocket::Close()
{
	CEventDispatch::Instance()->RemoveEvent(m_socket);
	RemoveBaseSocket(this);
	close(m_socket);
	ReleaseRef();
	return 0;
}

void CBaseSocket::_SetNonblock(int fd)
{
 	fcntl(fd,F_SETFL,O_NONBLOCK | fcntl(fd,F_GETFL));
}

void CBaseSocket::_SetReuseAddr(int fd)
{
	int reuse = 1;
	setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
}

void CBaseSocket::_SetAddr(const char* ip,uint16_t port,sockaddr_in* pAddr)
{
	memset(pAddr,0,sizeof(sockaddr_in));
	pAddr->sin_family = AF_INET;
	pAddr->sin_port = htons(port);
	pAddr->sin_addr.s_addr = inet_addr(ip);
		
}

void CBaseSocket::_AcceptNewSocket()
{
	int fd = 0;
	sockaddr_in peer_addr;
	socklen_t addr_len = sizeof(sockaddr_in);
	char ip_str[64];
	while((fd=accept(m_socket,(sockaddr*)&peer_addr,&addr_len))!=-1){
		CBaseSocket *pSocket = new CBaseSocket();
		uint32_t ip = ntohl(peer_addr.sin_addr.s_addr);
		uint16_t port = ntohs(peer_addr.sin_port);
		snprintf(ip_str,sizeof(ip_str),"%d.%d.%d.%d",ip>>24,(ip>>16)&0xFF,(ip>>8)&0xFF,ip&0xFF);
		loginfo("AcceptNewSocket, socket=%d from %s:%d",fd,ip_str,port);

		pSocket->SetCallback(m_callback);
		pSocket->SetCallbackData(m_callbackData);
		pSocket->SetSocket(fd);
		pSocket->SetState(SOCKET_STATE_CONNECTED);

		_SetNonblock(fd);
		AddBaseSocket(pSocket);
		CEventDispatch::Instance()->AddEvent(fd);
		m_callback(m_callbackData,NETLIB_MSG_CONNECT,(uint32_t)fd,NULL);
	}
}
