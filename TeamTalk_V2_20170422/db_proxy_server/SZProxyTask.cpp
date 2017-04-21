#include "SZProxyTask.h"

SZProxyTask::SZProxyTask(uint32_t conn_uuid,pdu_handler_t pdu_handler,SZPduBase* pPdu)
{
	m_conn_uuid = conn_uuid;
	m_pdu_handler = pdu_handler;
	m_pPdu = pPdu;
}
SZProxyTask::~SZProxyTask()
{
	if(m_pPdu)
		delete m_pPdu;
}

void SZProxyTask::Run()
{
	if(!m_pPdu){

	}else{
		if(m_pdu_handler)
		{
			m_pdu_handler(m_pPdu,m_conn_uuid);
		}
	}
}
