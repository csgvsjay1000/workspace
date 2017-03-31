#include "DBTestUser.h"
#include "../../base/util.h"


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
