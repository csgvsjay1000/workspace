#ifndef __SZImUser_h__
#define __SZImUser_h__

#include "SZHeaders.h"
#include <map>
#include <set>

class SZMsgConn;

class SZImUser
{
public:
	SZImUser(string user_name);
	~SZImUser();
	
private:
	string 		m_login_name;

	map<uint32_t,SZMsgConn*> 	m_conn_map;
	set<SZMsgConn*> 			m_unvalidate_conn_set;
};

typedef map<uint32_t,SZImUser*> ImUserMap_t;
typedef map<string,SZImUser*> 	IMUserMapByName_t;

class SZImUserManager
{
public:
	static SZImUserManager* Instance();
	SZImUser* GetImUserById(uint32_t user_id);
	SZImUser* GetImUserByLoginName(string login_name);

	bool AddImUserByLoginName(string login_name,SZImUser* pUser);
private:
	IMUserMapByName_t 	m_im_user_map_by_name;
	static SZImUserManager* s_Instance;
};

#endif
