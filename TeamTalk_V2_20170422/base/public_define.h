//
// public_define.h
//

#ifndef __public_define_h__
#define __public_define_h__

#include <string>
#include <stdint.h>

using namespace std;

typedef struct DBUserInfo_t
{
	uint32_t nId;  // 用户ID
	uint8_t nSex;  // 性别 1.男 2女
	uint8_t nStatus; // 用户状态 0 正常，1离职
	uint32_t nDeptId; // 部门Id
	string strNick;  // 昵称
	string strDomain;  //昵称拼音
	string strName; //真名
	string strTel; //手机号码
	string strEmail; //email
	string strAvatar; //头像
	string sign_info; //个性签名
	DBUserInfo_t& operator=(const DBUserInfo_t& rhs)
	{
		if(this != &rhs){
			nId = rhs.nId;
			nSex = rhs.nSex;
			nStatus = rhs.nStatus;
			nDeptId = rhs.nDeptId;
			strNick = rhs.strNick;
			strDomain = rhs.strDomain;
			strName = rhs.strName;
			strTel = rhs.strTel;
			strEmail = rhs.strEmail;
			strAvatar = rhs.strAvatar;
			sign_info = rhs.sign_info;
		}
		return *this;
	}
}DBUserInfo_t;

#endif
