#include "imconn.h"
#include "util.h"

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

}

int CImConn::Send(void* data, int len)
{

}
