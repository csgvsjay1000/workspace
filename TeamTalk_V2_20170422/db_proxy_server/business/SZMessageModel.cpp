#include "SZMessageModel.h"
#include "DBPool.h"

SZMessageModel* SZMessageModel::s_Instance = NULL;
SZMessageModel* SZMessageModel::Instance()
{
	if(s_Instance == NULL){
		s_Instance = new SZMessageModel();
	}
	return s_Instance;
}

bool SZMessageModel::SendMessage(uint32_t nRelateId,uint32_t nFromId,uint32_t nToId,IM::BaseDefine::MsgType nMsgType,uint32_t nCreateTime,uint32_t nMsgId,string& strMsgContent)
{
	CDBManager* pDBManager = CDBManager::Instance();
	CDBConn* pDBConn = pDBManager->GetDBConn(DB_MASTER);
	if(!pDBConn){
		log("no connection for db_master");
		return false;
	}
	bool bRet = false;
	string strTableName = "IMMessage_0";
	string strSql = "insert into "+strTableName+" (relateId,fromId,toId,msgId,content,status,type,created,updated) values(?,?,?,?,?,?,?,?,?) ";
	CPrepareStatement* stmt = new CPrepareStatement();
	if(stmt->Init(pDBConn->GetMysql(),strSql)){
		uint32_t nStatus = 0;
		uint32_t nType = nMsgType;
		uint32_t index = 0;
		stmt->SetParam(index++,nRelateId);
		stmt->SetParam(index++,nFromId);
		stmt->SetParam(index++,nToId);
		stmt->SetParam(index++,nMsgId);
		stmt->SetParam(index++,strMsgContent);
		stmt->SetParam(index++,nStatus);
		stmt->SetParam(index++,nType);
		stmt->SetParam(index++,nCreateTime);
		stmt->SetParam(index++,nCreateTime);
		
		bRet = stmt->ExecuteUpdate();
	}
	delete stmt;
	pDBManager->RelDBConn(pDBConn);
	return true;
}
