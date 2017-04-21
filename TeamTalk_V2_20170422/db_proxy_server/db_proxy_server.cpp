#include "SZBaseSocket.h"
#include "SZEventDispatch.h"
#include "SZProxyConn.h"

void* proxy_conn_callback(void* arg)
{
	return new SZProxyConn();
}

int main()
{
	printf("server start...\n");
	init_proxy_conn(2);
	SZBaseSocket socket;
	int listenFd = socket.Listen("127.0.0.1",8001,&proxy_conn_callback);
	SZEventDispatch::Instance()->StartDispatch();
	printf("server stop...\n");
	
	return 0;
}
