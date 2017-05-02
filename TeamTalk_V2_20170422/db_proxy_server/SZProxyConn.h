#ifndef __szmsg_conn_h__
#define __szmsg_conn_h__

#include "SZBaseSocket.h"
#include "SZThread.h"
#include <list>

typedef struct{
	uint32_t 	conn_uuid;
	SZPduBase* 	pPdu;
}ResponsePdu_t;

class SZProxyConn : public SZBaseSocket
{
public:	
	SZProxyConn();
	virtual void HandlePdu(SZPduBase* pPdu);
	virtual void ReadPacket();

	static void AddResponsePdu(uint32_t conn_uuid,SZPduBase* pPdu);
	static void SendResponsePduList();

private:
	static uint32_t s_uuid_alloctor;
	uint32_t m_uuid;
	static SZThreadNotify 	s_list_lock;
	static list<ResponsePdu_t*> s_response_pdu_list;
};

int init_proxy_conn(uint32_t thread_num);

#endif
