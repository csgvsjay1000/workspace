#include "SZImUser.h"

SZImUser::SZImUser(string user_name)
{
	m_login_name = user_name;
}
SZImUser::~SZImUser()
{

}

SZImUserManager* SZImUserManager::s_Instance = NULL;
SZImUserManager* SZImUserManager::Instance()
{
	if(!s_Instance){
		s_Instance = new SZImUserManager();
	}
	return s_Instance;
}

SZImUser* SZImUserManager::GetImUserById(uint32_t user_id)
{

	return NULL;
}
SZImUser* SZImUserManager::GetImUserByLoginName(string login_name)
{
	SZImUser* pUser = NULL;
	IMUserMapByName_t::iterator it = m_im_user_map_by_name.find(login_name);
	if(it != m_im_user_map_by_name.end()){
		pUser = it->second;
	}
	return pUser;
}

bool SZImUserManager::AddImUserByLoginName(string login_name,SZImUser* pUser)
{
	bool bRet = false;
	if(GetImUserByLoginName(login_name) == NULL){
		m_im_user_map_by_name[login_name] = pUser;
		bRet = true;
	}
	return bRet;
}

