#include "SZProxyConn.h"
#include "pb/IM.BaseDefine.pb.h"
#include "pb/IM.Login.pb.h"

using namespace IM::BaseDefine;

void SZProxyConn::HandlePdu(SZPduBase* pPdu)
{
	switch(pPdu->GetCommandId()){
		case CID_LOGIN_REQ_USERLOGIN:
			_HandleLoginRequest(pPdu);
			break;
	}
}

void SZProxyConn::_HandleLoginRequest(SZPduBase* pPdu) 
{
	IM::Login::IMLoginReq msg;
	msg.ParseFromArray(pPdu->GetBodyData(),pPdu->GetBodyLength());
	log("user_name: %s",msg.user_name().c_str());
	
	IM::Login::IMLoginRes rsp;
	rsp.set_result_code(REFUSE_REASON_NONE);
	rsp.set_result_string("成功");
	rsp.set_server_time(time(NULL));
	IM::BaseDefine::UserInfo *pUser = rsp.mutable_user_info();
	pUser->set_user_id(1);
	pUser->set_user_nick_name(msg.user_name());
	SZPduBase* pPduResp = new SZPduBase();
	pPduResp->SetPBMsg(&rsp);
	pPduResp->SetServiceId(IM::BaseDefine::SID_LOGIN);
	pPduResp->SetCommandId(IM::BaseDefine::CID_LOGIN_RES_USERLOGIN);
	Send(pPduResp->GetBuffer(),pPduResp->GetLength());
	delete pPduResp;
}
