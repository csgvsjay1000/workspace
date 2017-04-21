#include "MsgConn.h"
#include "util.h"

static UserMap_t g_msg_conn_user_map;
static ConnMap_t g_msg_conn_map;

void CMsgConn::OnConnect(int handle)
{
	m_handle = handle;
	g_msg_conn_map.insert(make_pair(handle,this));
	netlib_option(handle,NETLIB_OPT_SET_CALLBACK,(void*)imconn_callback);
	netlib_option(handle,NETLIB_OPT_SET_CALLBACK_DATA,(void*)&g_msg_conn_map);
}

void CMsgConn::HandlePdu(CImPdu* pPdu)
{
	loginfo("commandId: %d",pPdu->GetCommandId());
}
