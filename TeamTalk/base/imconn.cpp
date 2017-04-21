#include "imconn.h"
#include "util.h"
#include "netlib.h"

static CImConn* FindImConn(ConnMap_t* imconn_map,int handle)
{
	CImConn* pConn = NULL;
	ConnMap_t::iterator it = imconn_map->find(handle);
	if(it != imconn_map->end())
	{
		pConn = it->second;
		pConn->AddRef();
	}
	return pConn;
}

void imconn_callback(void* callback_data,uint8_t msg,uint32_t handle,void* pParam)
{
	if(!callback_data)
		return;
	ConnMap_t* conn_map = (ConnMap_t*)callback_data;
	CImConn* pConn = FindImConn(conn_map,handle);
	if(!pConn)
		return;
	switch(msg)
	{
		case NETLIB_MSG_CONFIRM:
			pConn->OnConfirm();
			break;
		case NETLIB_MSG_READ:
			pConn->OnRead();
			break;
		case NETLIB_MSG_WRITE:
			pConn->OnWrite();
			break;
		case NETLIB_MSG_CLOSE:
			pConn->OnClose();
			break;
		default:
			break;
	}
	pConn->ReleaseRef();
}

CImConn::CImConn()
{
	m_busy = false;
	m_handle = -1;
	m_recvBytes = 0;
	m_last_recv_tick = m_last_send_tick = get_tick_count();
}

int CImConn::Send(void* data, int len)
{
	m_last_send_tick = get_tick_count();
	if(m_busy)
	{
		m_simpleOutBuffer.Write(data,len);
		return len;
	}
	int offset = 0;
	int remain = len;
	while(remain>0)
	{
		int send_size = remain;
		if(send_size > NETLIB_MAX_SOCKET_BUF_SIZE){
			send_size = NETLIB_MAX_SOCKET_BUF_SIZE;
		}
		int ret = netlib_send(m_handle,(char*)data+offset,send_size);
		if(ret <= 0)
		{
			ret = 0;
			break;
		}
		offset += ret;
		remain -= ret;
	}
	if(remain > 0)
	{
		m_simpleOutBuffer.Write((char*)data+offset,remain);
		m_busy = true;
		loginfo("send busy, remain=%d ",m_simpleOutBuffer.GetWriteOffset());
	}
	else
	{
		OnWriteCompelete();
	}
	return len;
}

void CImConn::OnRead()
{
	for(;;)
	{
		uint32_t free_buf_len = m_simpleInBuffer.GetAllocSize()-m_simpleInBuffer.GetWriteOffset();
		if(free_buf_len < READ_BUF_SIZE)
			m_simpleInBuffer.Extend(READ_BUF_SIZE);
		int ret = netlib_recv(m_handle,m_simpleInBuffer.GetBuffer()+m_simpleInBuffer.GetWriteOffset(),READ_BUF_SIZE);
		if(ret <= 0)
			break;
		m_recvBytes += ret;
		m_simpleInBuffer.IncWriteOffset(ret);
		m_last_recv_tick = get_tick_count();
	}
	CImPdu* pPdu = NULL;
	try{
		while( (pPdu = CImPdu::ReadPdu(m_simpleInBuffer.GetBuffer(),m_simpleInBuffer.GetWriteOffset()))  )
		{
			uint32_t pdu_len = pPdu->GetLength();
			HandlePdu(pPdu);
			// 从m_simpleInBuffer 读完数据后删除数据
			m_simpleInBuffer.Read(NULL,pdu_len);	
			delete pPdu;
			pPdu = NULL;
		}
	}catch(std::exception* exp){

	}
}

void CImConn::OnWrite()
{
	if(!m_busy)
		return;
	while(m_simpleOutBuffer.GetWriteOffset() > 0)
	{
		int send_size = m_simpleOutBuffer.GetWriteOffset();
		if(send_size > NETLIB_MAX_SOCKET_BUF_SIZE)
			send_size = NETLIB_MAX_SOCKET_BUF_SIZE;
		int ret = netlib_send(m_handle,m_simpleOutBuffer.GetBuffer(),send_size);
		if(ret <= 0){
			ret = 0;
			break;
		}
		m_simpleOutBuffer.Read(NULL,ret);
	}
	if(m_simpleOutBuffer.GetWriteOffset() == 0)
		m_busy = false;
	loginfo("onWrite, remain=%d ",m_simpleOutBuffer.GetWriteOffset());
}
