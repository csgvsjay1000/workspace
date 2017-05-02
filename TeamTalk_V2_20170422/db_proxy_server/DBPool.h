//
// DBPool.h
//

#ifndef __DBPOOL_H__
#define __DBPOOL_H__

#include "SZHeaders.h"
#include <mysql.h>
#include <map>
#include <string>
#include <stdint.h>
#include <list>

#include "SZThread.h"

#define MAX_ESCAPE_STRING_LEN 	1024*10
#define DB_MASTER  	"teamtalk_master"
#define DB_SLAVE 	"teamtalk_slave"


using namespace std;

class CResultSet
{
public:
	CResultSet(MYSQL_RES* res);
	~CResultSet();
	
	bool Next();
	int GetInt(const char* key);
	char* GetString(const char* key);
	
private:
	int _GetIndex(const char* key);

	MYSQL_RES* 			m_res;
	MYSQL_ROW 			m_row;
	map<string,int> 	m_key_map;
};

class CPrepareStatement
{
public:
	CPrepareStatement();
	~CPrepareStatement();
	bool Init(MYSQL* mysql,string& sql);
	void SetParam(uint32_t index, int& value);
	void SetParam(uint32_t index, uint32_t& value);
	void SetParam(uint32_t index, string& value);
	void SetParam(uint32_t index, const string& value);
	
	bool ExecuteUpdate();

private:
	MYSQL_STMT* 	m_stmt;
	MYSQL_BIND* 	m_param_bind;
	uint32_t 		m_param_cnt;
};

class CDBPool;

class CDBConn
{
public:
	CDBConn(CDBPool* pDBPool);
	int Init();
	CDBPool* GetDBPool(){return m_pDBPool;}
	bool ExecuteUpdate(const char* sql_query);
	CResultSet* ExecuteQuery(const char* sql_query);
	MYSQL* GetMysql(){return m_mysql;}
	uint32_t GetInsertId();
private:
	CDBPool* 		m_pDBPool;
	MYSQL* 			m_mysql;
	char 			m_escape_string[MAX_ESCAPE_STRING_LEN + 1];

};

class CThreadNotify;

class CDBPool
{
public:
	CDBPool(const char* pool_name,const char*db_server_ip,uint16_t db_server_port,
			const char* user_name,const char* password,const char* db_name,int max_conn_cnt);

	int Init();
	CDBConn* GetDBConn();
	void RelDBConn(CDBConn* pConn);

	const char* GetPoolName(){return m_pool_name.c_str();}
	const char* GetDBServerIP(){return m_db_server_ip.c_str();}
	uint16_t GetDBServerPort(){return m_db_server_port;}
	const char* GetUserName(){return m_username.c_str();}
	const char* GetPassword(){return m_password.c_str();}
	const char* GetDBName(){return m_db_name.c_str();}

private:
	string 			m_pool_name;
	string 			m_db_server_ip;
	uint16_t 		m_db_server_port;
	string 			m_username;
	string 			m_password;
	string 			m_db_name;
	int 			m_db_cur_conn_cnt;
	int 			m_db_max_conn_cnt;
	list<CDBConn*> 	m_free_list; 		//空闲连接 	
	SZThreadNotify 	m_free_notify;
};

class CDBManager
{
public:
	static CDBManager* Instance();
	int Init();

	CDBConn* GetDBConn(const char* dbpool_name);
	void RelDBConn(CDBConn* pConn);

private:
	static CDBManager* 		s_Instance;
	map<string,CDBPool*> 	m_dbpool_map;
};

#endif
