#include "SZLogin.h"
#include <stdio.h>
#include "pb/IM.Server.pb.h"
#include "SZProxyConn.h"
//using namespace DB_PROXY;

void DB_PROXY::doLogin(SZPduBase* pPdu,uint32_t conn_uuid)
{
	IM::Server::IMValidateReq msg;
	IM::Server::IMValidateRsp msgResp;
	if(!msg.ParseFromArray(pPdu->GetBodyData(),pPdu->GetBodyLength()))
	{
		printf("prase error\n");
	}	
	printf("service_id: %d\n",pPdu->GetServiceId());
	printf("command_id: %d\n",pPdu->GetCommandId());
	printf("user_name: %s\n",msg.user_name().c_str());
	msgResp.set_user_name(msg.user_name());
	msgResp.set_result_code(0);
	msgResp.set_result_string("成功");
	SZPduBase* pPduResp = new SZPduBase;
	pPduResp->SetPBMsg(&msgResp);
	pPduResp->SetServiceId(IM::BaseDefine::SID_OTHER);
	pPduResp->SetCommandId(IM::BaseDefine::CID_OTHER_VALIDATE_RSP);
	SZProxyConn::AddResponsePdu(conn_uuid,pPduResp);

}
