#ifndef __SZProxyTask_h__
#define __SZProxyTask_h__

#include "SZTask.h"
#include "SZPduBase.h"

typedef void (*pdu_handler_t)(SZPduBase* pPdu,uint32_t conn_uuid);

class SZProxyTask : public SZTask
{
public:
	SZProxyTask(uint32_t conn_uuid,pdu_handler_t pdu_handler,SZPduBase* pPdu);
	virtual ~SZProxyTask();

	virtual void Run();

private:
	uint32_t 		m_conn_uuid;
	pdu_handler_t 	m_pdu_handler;
	SZPduBase* 		m_pPdu;
};

#endif
