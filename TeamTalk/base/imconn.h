#ifndef __imconn_h__
#define __imconn_h__

#include "netlib.h"
#include "ImPduBase.h"
#include <string>

using namespace std;

#define SERVER_HEARTBEAT_INTERVAL 		5000    //5 秒
#define SERVER_TIMEOUT 					30000   //30 秒
#define CLIENT_HEARTBEAT_INTERVAL 		30000   //30 秒
#define CLIENT_TIMEOUT 					120000  //120 秒
#define MOBILE_CLIENT_TIMEOUT 			60000*5 //5 分钟
#define READ_BUF_SIZE  2048

class CImConn : public CRefObject
{
public:
	CImConn();
	~CImConn(){}
	
	bool IsBusy(){return m_busy;}
	int Send(void* data, int len);
	int SendPdu(CImPdu* pPdu){return Send(pPdu->GetBuffer(),pPdu->GetLength());}

	virtual void OnConnect(int handle){}
	virtual void OnConfirm(){}
	virtual void OnRead(){}
	virtual void OnWrite(){}
	virtual void OnClose(){}
	virtual void OnTimer(uint64_t curr_tick){}
	virtual void OnWriteCompelete(){}

private:
	int 		m_handle;
	bool 		m_busy;

	string 		m_peerIp;
	uint16_t 	m_peerPort;
	CSimpleBuffer 	m_simpleInBuffer;
	CSimpleBuffer 	m_simpleOutBuffer;

	bool 		m_policyConn;
	uint32_t 	m_recvBytes;
	uint64_t 	m_last_send_tick;
	uint64_t 	m_last_recv_tick;
	uint64_t 	m_last_all_user_tick;
};

typedef hash_map<int, CImConn*> ConnMap_t;
typedef hash_map<uint32_t, CImConn*> UserMap_t;

void imconn_callback(void* callback_data,uint8_t msg,uint32_t handle,void* pParam);

#endif
