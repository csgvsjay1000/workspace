#include "SZBaseSocket.h"
#include "SZEventDispatch.h"
#include "SZClientConn.h"

void* client_callback(void* pParam)
{
	SZClientConn* pConn = (SZClientConn*)pParam;
	pConn->OnConfirm();
	return NULL;
}

int main(){
	SZClientConn* pSocket = new SZClientConn();
	pSocket->Connect("127.0.0.1",8000,client_callback);
	SZEventDispatch::Instance()->StartDispatch();

	return 0;
}

