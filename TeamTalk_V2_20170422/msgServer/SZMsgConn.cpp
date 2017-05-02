#include "SZMsgConn.h"
#include "pb/IM.Server.pb.h"
#include "SZDBServConn.h"

void SZMsgConn::HandlePdu(SZPduBase* pPdu)
{
	IM::Server::IMValidateReq msg;
	if(!msg.ParseFromArray(pPdu->GetBodyData(),pPdu->GetBodyLength()))
	{
		printf("prase error\n");
	}	
	printf("service_id: %d\n",pPdu->GetServiceId());
	printf("command_id: %d\n",pPdu->GetCommandId());
	printf("user_name: %s\n",msg.user_name().c_str());

	
	//SZDBServConn* pDBConn = get_db_serv_conn();
	//pDBConn->Send(pPdu->GetBuffer(),pPdu->GetLength());
	
}

