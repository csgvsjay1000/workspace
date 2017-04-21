#include "SZBaseSocket.h"
#include "SZEventDispatch.h"
#include <string>
#include <iostream>

#include "SZSimpleBuffer.h"
#include "SZPduBase.h"
#include "IM.Server.pb.h"
#include "SZClientConn.h"
using namespace std;
using namespace IM::Server;

void* client_callback(void* pParam)
{
	SZClientConn* pConn = (SZClientConn*)pParam;
	pConn->OnConfirm();
	return NULL;
}

int main()
{

	SZSimpleBuffer sb;
	
	
	SZClientConn* pSocket = new SZClientConn();
	int socket = pSocket->Connect("127.0.0.1",8001,&client_callback);
	SZEventDispatch::Instance()->StartDispatch();
/*
	string str;
	SZPduBase pdu;
	while(true)
	{
		cin>>str;
		if(str == "break")
		{
			break;
		}
		IMValidateReq req;
		req.set_user_name(str);
		req.set_password("123456");	
		pdu.SetPBMsg(&req);
		pdu.SetServiceId(1);
		pdu.SetCommandId(2);
		pSocket->Send(pdu.GetBuffer(),pdu.GetLength());
	}*/
	return 0;
}
