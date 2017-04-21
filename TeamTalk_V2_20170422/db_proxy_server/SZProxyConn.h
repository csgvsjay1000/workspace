#ifndef __szmsg_conn_h__
#define __szmsg_conn_h__

#include "SZBaseSocket.h"

class SZProxyConn : public SZBaseSocket
{
public:	
	SZProxyConn();
	virtual void HandlePdu(SZPduBase* pPdu);
	virtual void ReadPacket();
private:
	static uint32_t s_uuid_alloctor;
	uint32_t m_uuid;
};

int init_proxy_conn(uint32_t thread_num);

#endif
