#ifndef __szbasesocket_h__
#define __szbasesocket_h__

#include "SZHeaders.h"
#include "SZPduBase.h"

enum{
	SZSOCKET_STATE_LISTENNING = 1,
	SZSOCKET_STATE_CONNECTED = 2,
	SZSOCKET_STATE_CONNECTING = 3

};

class SZBaseSocket
{
public:
	int Listen(const char* ip,uint16_t port,callback_t callback);
	int Connect(const char* ip,uint16_t port,callback_t callback);

	int AcceptNewSocket();
	void OnRead();
	void OnWrite();
	void OnClose();

	void Send(void* buf,int len);
	void Recv(void* buf,int len);

public:
	int GetSocket(){return m_socket;}
	void SetSocket(int socket){m_socket = socket;}

	void SetState(uint16_t state){m_state = state;}
protected:
	virtual void HandlePdu(SZPduBase* pPdu){};
	SZSimpleBuffer 	m_simpleInBuffer;
	int 	m_socket;
	virtual void ReadPacket();
private:
	void _SetReuseAddr(int fd);
	void _SetAddr(const char* ip,uint16_t port,sockaddr_in* pAddr);
	void _SetNonblock(int fd);
	bool _IsBlock(int err_code);

private:
	uint16_t m_state;
	callback_t m_callback;	
};

typedef hash_map<int,SZBaseSocket*> SZConnMap_t;
SZBaseSocket* FindBaseSocket(int fd);

#endif

