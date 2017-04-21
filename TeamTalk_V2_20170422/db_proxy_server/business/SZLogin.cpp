#include "SZLogin.h"
#include <stdio.h>
#include "pb/IM.Server.pb.h"
//using namespace DB_PROXY;

void DB_PROXY::doLogin(SZPduBase* pPdu,uint32_t conn_uuid)
{
	IM::Server::IMValidateReq msg;
	if(!msg.ParseFromArray(pPdu->GetBodyData(),pPdu->GetBodyLength()))
	{
		printf("prase error\n");
	}	
	printf("service_id: %d\n",pPdu->GetServiceId());
	printf("command_id: %d\n",pPdu->GetCommandId());
	printf("user_name: %s\n",msg.user_name().c_str());


}
