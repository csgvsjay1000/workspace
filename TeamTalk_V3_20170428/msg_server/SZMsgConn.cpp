#include "SZMsgConn.h"
#include "pb/IM.BaseDefine.pb.h"
#include "pb/IM.Login.pb.h"
#include "SZImUser.h"
#include "SZDBServConn.h"

using namespace IM::BaseDefine;

void SZMsgConn::HandlePdu(SZPduBase* pPdu)
{
	switch(pPdu->GetCommandId()){
		case CID_LOGIN_REQ_USERLOGIN:
			_HandleLoginRequest(pPdu);
			break;
	}
}

void SZMsgConn::_HandleLoginRequest(SZPduBase* pPdu) 
{
	IM::Login::IMLoginReq msg;
	msg.ParseFromArray(pPdu->GetBodyData(),pPdu->GetBodyLength());
	log("user_name: %s",msg.user_name().c_str());
	m_login_name = msg.user_name();	
	SZImUser* pImUser = SZImUserManager::Instance()->GetImUserByLoginName(m_login_name);
	if(!pImUser){
		pImUser = new SZImUser(m_login_name);
		SZImUserManager::Instance()->AddImUserByLoginName(m_login_name,pImUser);
	}

	SZDBServConn* pDBConn = get_db_serv_conn();
	pDBConn->Send(pPdu->GetBuffer(),pPdu->GetLength());


}
