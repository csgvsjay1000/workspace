#include "SZClientConn.h"
#include <iostream>

#include <string>
#include "SZSimpleBuffer.h"
#include "SZPduBase.h"
#include "IM.Server.pb.h"
#include <pthread.h>

using namespace std;
using namespace IM::Server;

void* SZClientConn::HandleConn(void* arg)
{
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
	}
	return NULL;
}

void* test(void* arg)
{
	SZClientConn *pConn = (SZClientConn*)arg;
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
		pConn->Send(pdu.GetBuffer(),pdu.GetLength());
	}

	return NULL;
}

void SZClientConn::OnConfirm()
{
	pthread_t thread;
	pthread_create(&thread,NULL,test,this);
	//pthread_create()
}
