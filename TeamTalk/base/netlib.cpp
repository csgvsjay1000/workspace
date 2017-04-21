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
int netlib_connect(const char* ip,uint16_t port,callback_t callback,void* callback_data)
{
	CBaseSocket* pSocket = new CBaseSocket();
	if(!pSocket)
		return -1;
	return pSocket->Connect(ip,port,callback,callback_data);

}

int netlib_send(int handle,void* buf,int len)
{
	CBaseSocket* pSocket = FindBaseSocket(handle);
	if(!pSocket)
	{
		return -1;
	}
	int ret = pSocket->Send(buf,len);
	pSocket->ReleaseRef();
	return ret;
}

int netlib_recv(int handle,void* buf,int len)
{
	CBaseSocket* pSocket = FindBaseSocket(handle);
	if(!pSocket)
	{
		return -1;
	}
	int ret = pSocket->Recv(buf,len);
	pSocket->ReleaseRef();
	return ret;
}
int netlib_close(int handle)
{
	CBaseSocket* pSocket = FindBaseSocket(handle);
	if(!pSocket)
	{
		return -1;
	}
	int ret = pSocket->Close();
	pSocket->ReleaseRef();
	return ret;
}
void netlib_eventloop(int timeout)
{
	CEventDispatch::Instance()->StartDispatch(timeout);
}
int netlib_option(int handle,int opt,void* optval)
{
	CBaseSocket* pSocket = FindBaseSocket(handle);
	if(!pSocket)
		return -1;
	switch(opt)
	{
		case NETLIB_OPT_SET_CALLBACK:
			pSocket->SetCallback((callback_t)optval);
			break;
		case NETLIB_OPT_SET_CALLBACK_DATA:
			pSocket->SetCallbackData(optval);
			break;

	}
	pSocket->ReleaseRef();
	return 0;
}
