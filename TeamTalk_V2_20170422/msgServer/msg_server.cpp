#include "SZBaseSocket.h"
#include "SZEventDispatch.h"
#include "SZMsgConn.h"
#include "SZDBServConn.h"

void* msg_conn_callback(void* pParam)
{
	return new SZMsgConn();
}

int main()
{
	printf("server start...\n");

	SZBaseSocket socket;
	int listenFd = socket.Listen("127.0.0.1",8000,&msg_conn_callback);

	init_db_serv_conn();

	SZEventDispatch::Instance()->StartDispatch();
	printf("server stop...\n");
	
	return 0;
}
