#include "netlib.h"
#include "BaseSocket.h"
#include "EventDispatch.h"

int netlib_listen(const char* ip,uint16_t port,callback_t callback,void* callback_data)
{
	CBaseSocket* pSocket = new CBaseSocket();
	if(!pSocket)
		return -1;
	pSocket->Listen(ip,port,callback,callback_data);
	return 0;
}

void netlib_eventloop(int timeout)
{
	CEventDispatch::Instance()->StartDispatch(timeout);
}
