#include "DBTestUser.h"
#include "SZHeaders.h"
#include "SZSessionModel.h"
#include "IM.BaseDefine.pb.h"

void CDBUserTest::TestInsert()
{
	DBUserInfo_t user;
	user.nSex = 1;
	user.nStatus = 0;
	user.nDeptId = 1;
	user.strNick = "岗岗";
	
	if(!CUserModel::Instance()->InsertUser(user)){
		log("InsertUser failed. user: %s",user.strNick.c_str());
		return;
	}
	loginfo("InsertUser successed. user: %s",user.strNick.c_str());
}

void CDBUserTest::TestSelect()
{
	DBUserInfo_t user;
	if(!CUserModel::Instance()->GetUser((uint32_t)1,user)){
		log("GetUser failed.");
		return;
	}
	
	loginfo("user.name: %s",user.strName.c_str());
}

void CDBUserTest::TestAddSession()
{
	//uint32_t AddSession(uint32_t nUserId,uint32_t nPeerId,uint32_t nType);
	SZSessionModel::Instance()->AddSession(1,2,IM::BaseDefine::MSG_TYPE_SINGLE_TEXT);
}
