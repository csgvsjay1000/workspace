#include "SZDBServConn.h"
#include <vector>

static uint32_t 	g_db_server_count = 0;
static uint32_t 	g_db_server_login_count = 0;

vector<SZDBServConn*> g_db_server_list;

static SZConnMap_t g_db_server_conn_map;

void* dbserv_callback(void* pParam)
{
	//SZClientConn* pConn = (SZClientConn*)pParam;
	//pConn->OnConfirm();
	return NULL;
}
void init_db_serv_conn()
{
	g_db_server_count = 20;
	g_db_server_login_count = 5;
	for(int i=0;i<g_db_server_count;i++)
	{
		SZDBServConn* pConn = new SZDBServConn();
		int ret = pConn->Connect("127.0.0.1",8001,&dbserv_callback);
		g_db_server_conn_map.insert(make_pair(ret,pConn));
		g_db_server_list.push_back(pConn);	
	}	
}

static SZDBServConn* getDBServConnInRange(uint32_t start_pos,uint32_t stop_pos)
{
	uint32_t i=0;
	SZDBServConn* pConn = NULL;
	for(i=start_pos;i<stop_pos;i++)
	{
		pConn = g_db_server_list[i];
		break;
	}	

	return pConn;
}


SZDBServConn* get_db_serv_conn()
{
	
	return getDBServConnInRange(g_db_server_login_count,g_db_server_count);
}
