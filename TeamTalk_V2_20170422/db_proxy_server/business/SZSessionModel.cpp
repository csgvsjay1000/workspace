#include "SZSessionModel.h"
#include "DBPool.h"

SZSessionModel* SZSessionModel::s_Instance = NULL;
SZSessionModel* SZSessionModel::Instance()
{
	if(!s_Instance){
		s_Instance = new SZSessionModel();
	}
	return s_Instance;
}

uint32_t SZSessionModel::GetSessionId(uint32_t nUserId,uint32_t nPeerId,uint32_t nType,bool isAll)
{
	CDBManager* pDBManager = CDBManager::Instance();
	CDBConn* pDBConn = pDBManager->GetDBConn(DB_SLAVE);
	uint32_t nSessionId = -1;
	if(!pDBConn){
		return nSessionId;
	}	
	string sql;
	if(isAll){
		sql = "select id from IMRecentSession where userId="+int2string(nUserId)+" and peerId="+int2string(nPeerId)+" and type="+int2string(nType);
	}else{
		sql = "select id from IMRecentSession where userId="+int2string(nUserId)+" and peerId="+int2string(nPeerId)+" and type="+int2string(nType)+" and status=0";
	}
	CResultSet* pResultSet = pDBConn->ExecuteQuery(sql.c_str());
	if(pResultSet){
		while(pResultSet->Next()){
			nSessionId = pResultSet->GetInt("id");
		}
		delete pResultSet;
	}
	pDBManager->RelDBConn(pDBConn);
	return nSessionId;
}
	
uint32_t SZSessionModel::AddSession(uint32_t nUserId,uint32_t nPeerId,uint32_t nType){
	uint32_t nSessionId = -1;
	nSessionId = GetSessionId(nUserId,nPeerId,nType,true);
	uint32_t nTimeNow = time(NULL);
	CDBManager* pDBManager = CDBManager::Instance();
	CDBConn* pDBConn = pDBManager->GetDBConn(DB_MASTER);
	if(!pDBManager){
		return nSessionId;
	}
	if(-1 != nSessionId){
		string sql = "update IMRecentSession set status=0,updated="+int2string(nTimeNow)+" where id="+int2string(nSessionId);
		bool bRet = pDBConn->ExecuteUpdate(sql.c_str());
		if(!bRet){
			nSessionId = -1;
		}
		return nSessionId;
	}
	string sql = "insert into IMRecentSession (userId,peerId,type,status,created,updated) values(?,?,?,?,?,?)";
	CPrepareStatement* stmt = new CPrepareStatement();
	if(stmt->Init(pDBConn->GetMysql(),sql)){
		uint32_t nStatus = 0;
		uint32_t index = 0;
		stmt->SetParam(index++,nUserId);
		stmt->SetParam(index++,nPeerId);
		stmt->SetParam(index++,nType);
		stmt->SetParam(index++,nStatus);
		stmt->SetParam(index++,nTimeNow);
		stmt->SetParam(index++,nTimeNow);

		bool bRet = stmt->ExecuteUpdate();
		if(bRet){
			nSessionId = pDBConn->GetInsertId();
		}
		
	}	
	delete stmt;
	pDBManager->RelDBConn(pDBConn);
	return nSessionId;
}
