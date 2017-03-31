#include "UserModel.h"
#include "DBPool.h"

#define DB_MASTER  	"teamtalk_master"
#define DB_SLAVE 	"teamtalk_slave"

CUserModel* CUserModel::m_pInstance = NULL;
CUserModel* CUserModel::Instance()
{
	if(!m_pInstance){
		m_pInstance = new CUserModel;
	}
	return m_pInstance;
}
bool CUserModel::InsertUser(DBUserInfo_t& user)
{
	CDBManager* pDBManager = CDBManager::Instance();
	CDBConn* pDBConn = pDBManager->GetDBConn(DB_MASTER);
	if(!pDBConn){
		log("no db connection for %s",DB_MASTER);
		return false;
	}
	bool ret = false;
	string sql = "insert into IMUser(sex,nick,domain,name,phone,email,avatar,sign_info,departId,status,created,updated) values(?,?,?,?,?,?,?,?,?,?,?,?)";
	CPrepareStatement* stmt = new CPrepareStatement();
	if(stmt->Init(pDBConn->GetMysql(),sql)){
		uint32_t nNow = (uint32_t)time(NULL);
		uint32_t index = 0;
		uint32_t nGender = user.nSex;
		uint32_t nStatus = user.nStatus;
		stmt->SetParam(index++,nGender);
		stmt->SetParam(index++,user.strNick);
		stmt->SetParam(index++,user.strDomain);
		stmt->SetParam(index++,user.strName);
		stmt->SetParam(index++,user.strTel);
		stmt->SetParam(index++,user.strEmail);
		stmt->SetParam(index++,user.strAvatar);
		stmt->SetParam(index++,user.sign_info);
		stmt->SetParam(index++,user.nDeptId);
		stmt->SetParam(index++,nStatus);
		stmt->SetParam(index++,nNow);
		stmt->SetParam(index++,nNow);
		
		ret = stmt->ExecuteUpdate();
		if(!ret){
			log("insert user failed: %s",sql.c_str());
		}
	}	
	delete stmt;

	pDBManager->RelDBConn(pDBConn);
	return ret;

}
