#include "SZBaseSocket.h"
#include "SZEventDispatch.h"
#include "SZProxyConn.h"
#include "SZCachePool.h"
#include "DBPool.h"
#include "test/DBTestUser.h"


void* proxy_conn_callback(void* arg)
{
	return new SZProxyConn();
}

void test_db()
{
	CDBUserTest test;
	//test.TestInsert();	
	test.TestAddSession();
}

int main()
{
	printf("server start...\n");
	//初始化CachePool
	SZCacheManager::Instance();
	
	CDBManager::Instance();

	//test_db();

	init_proxy_conn(1);
	SZBaseSocket socket;
	int listenFd = socket.Listen("127.0.0.1",8001,&proxy_conn_callback);
	SZEventDispatch::Instance()->StartDispatch();
	printf("server stop...\n");
	
	return 0;
}
