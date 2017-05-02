#include "SZMessageContent.h"
#include <stdio.h>
#include "pb/IM.Message.pb.h"
#include "SZProxyConn.h"
#include "SZMessageModel.h"
#include "SZSessionModel.h"

void DB_PROXY::sendMessage(SZPduBase* pPdu,uint32_t conn_uuid)
{
	IM::Message::IMMsgData msg;
	if(!msg.ParseFromArray(pPdu->GetBodyData(),pPdu->GetBodyLength()))
	{
		printf("prase error\n");
	}	

	IM::BaseDefine::MsgType nMsgType = msg.msg_type();
	uint32_t nFromId = msg.from_user_id();
	uint32_t nToId = msg.to_session_id();
	uint32_t nCreateTime = msg.create_time();
	uint32_t nMsgLen = msg.msg_data().length();
	uint32_t nNow = (int32_t)time(NULL);
	uint32_t nMsgId = -1;
	uint32_t nSessionId = -1;
	SZMessageModel* pMsgModel = SZMessageModel::Instance();
	if(nMsgType == IM::BaseDefine::MSG_TYPE_SINGLE_TEXT){

	}
	/*
	msgResp.set_user_name(msg.user_name());
	msgResp.set_result_code(0);
	msgResp.set_result_string("成功");
	SZPduBase* pPduResp = new SZPduBase;
	pPduResp->SetPBMsg(&msgResp);
	pPduResp->SetServiceId(IM::BaseDefine::SID_OTHER);
	pPduResp->SetCommandId(IM::BaseDefine::CID_OTHER_VALIDATE_RSP);
	SZProxyConn::AddResponsePdu(conn_uuid,pPduResp);
	*/
}
