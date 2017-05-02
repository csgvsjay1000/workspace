#include "SZProxyConn.h"
#include "pb/IM.Server.pb.h"
#include "SZHandlerMap.h"
#include "SZThreadPool.h"
#include "SZEventDispatch.h"

static SZHandlerMap* g_pHanderMap;
static SZThreadPool g_ThreadPool;
uint32_t SZProxyConn::s_uuid_alloctor = 0;
static SZConnMap_t g_uuidConnMap;
SZThreadNotify SZProxyConn::s_list_lock;
list<ResponsePdu_t*> SZProxyConn::s_response_pdu_list;

void* proxy_loop_callback(void* arg)
{
	SZProxyConn::SendResponsePduList();
	return NULL;
}

int init_proxy_conn(uint32_t thread_num)
{
	g_pHanderMap = SZHandlerMap::Instance();
	g_ThreadPool.Init(thread_num);
	SZEventDispatch::Instance()->AddLoop(proxy_loop_callback,NULL);
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

}
SZProxyConn::SZProxyConn()
{
	m_uuid = ++SZProxyConn::s_uuid_alloctor;
	g_uuidConnMap.insert(make_pair(m_uuid,this));
}
static SZProxyConn* get_proxy_conn_by_uuid(uint32_t uuid){
	SZProxyConn* pConn = NULL;
	SZConnMap_t::iterator it = g_uuidConnMap.find(uuid);
	if(it != g_uuidConnMap.end()){
		pConn = (SZProxyConn*)it->second;
	}
	return pConn;
}
void SZProxyConn::AddResponsePdu(uint32_t conn_uuid,SZPduBase* pPdu)
{
	ResponsePdu_t* pResp = new ResponsePdu_t;
	pResp->conn_uuid = conn_uuid;
	pResp->pPdu = pPdu;

	s_list_lock.Lock();
	s_response_pdu_list.push_back(pResp);
	s_list_lock.Unlock();
}
void SZProxyConn::SendResponsePduList()
{
	s_list_lock.Lock();
	while(!s_response_pdu_list.empty()){
		ResponsePdu_t* pResp = s_response_pdu_list.front();
		s_response_pdu_list.pop_front();
		s_list_lock.Unlock();
		SZProxyConn* pConn = get_proxy_conn_by_uuid(pResp->conn_uuid);
		if(pConn){
			if(pResp->pPdu){
				pConn->Send(pResp->pPdu->GetBuffer(),pResp->pPdu->GetLength());
			}
		}
		if(pResp->pPdu){
			delete pResp->pPdu;
		}
		delete pResp;
		s_list_lock.Lock();
			
	}
	s_list_lock.Unlock();
}
