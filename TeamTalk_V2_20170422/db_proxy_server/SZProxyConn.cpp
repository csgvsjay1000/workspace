#include "SZProxyConn.h"
#include "pb/IM.Server.pb.h"
#include "SZHandlerMap.h"
#include "SZThreadPool.h"

static SZHandlerMap* g_pHanderMap;
static SZThreadPool g_ThreadPool;
uint32_t SZProxyConn::s_uuid_alloctor = 0;
static SZConnMap_t g_uuidConnMap;


int init_proxy_conn(uint32_t thread_num)
{
	g_pHanderMap = SZHandlerMap::Instance();
	g_ThreadPool.Init(thread_num);
	return 0;
}
void SZProxyConn::ReadPacket()
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

}

void SZProxyConn::HandlePdu(SZPduBase* pPdu)
{
	pdu_handler_t handler = g_pHanderMap->GetHandler(pPdu->GetCommandId());
	if(!handler)
	{
		return;
	}
	SZTask* pTask = new SZProxyTask(m_uuid,handler,pPdu);
	g_ThreadPool.AddTask(pTask);
/*
	IM::Server::IMValidateReq msg;
	if(!msg.ParseFromArray(pPdu->GetBodyData(),pPdu->GetBodyLength()))
	{
		printf("prase error\n");
	}	
	printf("service_id: %d\n",pPdu->GetServiceId());
	printf("command_id: %d\n",pPdu->GetCommandId());
	printf("user_name: %s\n",msg.user_name().c_str());
*/	
}
SZProxyConn::SZProxyConn()
{
	m_uuid = ++SZProxyConn::s_uuid_alloctor;
	g_uuidConnMap.insert(make_pair(m_uuid,this));
}
