#include "SZClientConn.h"
#include <iostream>

#include <string>
#include "SZSimpleBuffer.h"
#include "SZPduBase.h"
#include "IM.Server.pb.h"
#include <pthread.h>

using namespace std;
using namespace IM::Server;

void SZClientConn::HandlePdu(SZPduBase* pPdu)
{
	IM::Server::IMValidateRsp msgResp;
	if(!msgResp.ParseFromArray(pPdu->GetBodyData(),pPdu->GetBodyLength()))
	{
		printf("prase error\n");
	}	
	printf("service_id: %d\n",pPdu->GetServiceId());
	printf("command_id: %d\n",pPdu->GetCommandId());
	printf("user_name: %s\n",msgResp.result_string().c_str());

	
}
void SZClientConn::OnConfirm()
{
		string str;
	SZPduBase pdu;
	IMValidateReq req;
		str = "csg";
		req.set_user_name(str);
		req.set_password("123456");	
		pdu.SetPBMsg(&req);
		pdu.SetServiceId(IM::BaseDefine::SID_OTHER);
		pdu.SetCommandId(IM::BaseDefine::CID_OTHER_VALIDATE_REQ);
		Send(pdu.GetBuffer(),pdu.GetLength());
}


