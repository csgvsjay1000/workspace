#ifndef __BaseSocket_h__
#define __BaseSocket_h__

#include <sys/socket.h>
#include <string>

#include "ostype.h"
#include "util.h"

using namespace std;

enum{
	SOCKET_STATE_IDLE,
	SOCKET_STATE_LISTENING,
	SOCKET_STATE_CONNECTING,
	SOCKET_STATE_CONNECTED,
	SOCKET_STATE_CLOSING
};

class CBaseSocket : public CRefObject
{
public:
	CBaseSocket();
	~CBaseSocket(){};
	int Listen(const char* ip,uint16_t port,callback_t callback,void* callback_data);
	int Connect(const char* ip,uint16_t port,callback_t callback,void* callback_data);
	
	void OnRead();
	void OnWrite();
	void OnClose();

	int Send(void* buf,int len);
	int Recv(void* buf,int len);
	int Close();

public:
	int GetSocket(){return m_socket;}
	
	void SetServerIp(const char* ip){m_serverIp = ip;}
	void SetServerPort(uint16_t port){m_serverPort = port;}
	void SetCallback(callback_t callback){m_callback = callback;}
	void SetCallbackData(void* data){m_callbackData = data;}

	void SetState(uint8_t state){m_state = state;}
	void SetSocket(int socket){m_socket = socket;}

private:
	void _SetNonblock(int fd);
	void _SetReuseAddr(int fd);
	void _SetAddr(const char* ip,uint16_t port,sockaddr_in* pAddr);
	bool _IsBlock();
	void _AcceptNewSocket();

private:
	string 		m_serverIp;
	uint16_t 	m_serverPort;
	callback_t 	m_callback;
	void* 		m_callbackData; 

	uint8_t 	m_state;
	int 		m_socket;
	
};

CBaseSocket* FindBaseSocket(int fd);

#endif
