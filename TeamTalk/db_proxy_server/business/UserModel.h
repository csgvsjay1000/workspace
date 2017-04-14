//
// UserModel.h
//

#ifndef __usermodel_h__
#define __usermodel_h__

#include "../base/public_define.h"

class CUserModel
{
public:
	static CUserModel* Instance();

	bool InsertUser(DBUserInfo_t& cUser);
	bool GetUser(uint32_t nUserId,DBUserInfo_t& cUser);	
private:
	static CUserModel* m_pInstance;
};

#endif
