#include "DBPool.h"
#include "../base/ConfigFileReader.h"
#include <stdlib.h>
#include "../base/Thread.h"

//// CResultSet
CResultSet::CResultSet(MYSQL_RES* res)
{
	m_res = res;
	int num_fields = mysql_num_fields(m_res);	
	MYSQL_FIELD *fields = mysql_fetch_field(m_res);
	for(int i=0;i<num_fields;i++)
	{
		m_key_map.insert(make_pair(fields[i].name,i));
	}
}
CResultSet::~CResultSet()
{
	if(m_res)
	{
		mysql_free_result(m_res);
		m_res = NULL;
	}
}

CPrepareStatement::CPrepareStatement()
{
	
}

CPrepareStatement::~CPrepareStatement()
{
	
}

CDBConn::CDBConn(CDBPool* pDBPool)
{
	m_pDBPool = pDBPool;
	m_mysql = NULL;
}

/// CDBConn
int CDBConn::Init()
{
	m_mysql = mysql_init(NULL);
	if(!m_mysql){
		log("mysql init failed");
		return 1;
	}
	my_bool reconnect = true;
   	mysql_options(m_mysql,MYSQL_OPT_RECONNECT,&reconnect);
	mysql_options(m_mysql,MYSQL_SET_CHARSET_NAME,"utf8mp4");

	if(!mysql_real_connect(m_mysql,m_pDBPool->GetDBServerIP(),m_pDBPool->GetUserName(),m_pDBPool->GetPassword(),m_pDBPool->GetDBName(),m_pDBPool->GetDBServerPort(),NULL,0)){
		log("mysql_real_connect failed: %s",mysql_error(m_mysql));
		return 2;
	}
	loginfo("mysql_real_connect successed");
	return 0;
}

/// CDBPool
CDBPool::CDBPool(const char* pool_name,const char*db_server_ip,uint16_t db_server_port,
			const char* user_name,const char* password,const char* db_name,int max_conn_cnt)
{
	m_pool_name = pool_name;
	m_db_server_ip = db_server_ip;
	m_db_server_port = db_server_port;
	m_username = user_name;
	m_password = password;
	m_db_name = db_name;
	m_db_max_conn_cnt = max_conn_cnt;	
}

int CDBPool::Init()
{
	for(int i=0;i<m_db_cur_conn_cnt;i++){
		CDBConn* pDBConn = new CDBConn(this);
		int ret = pDBConn->Init();
		if(ret){
			delete pDBConn;
			return ret;
		}
		m_free_list.push_back(pDBConn);
	}
	loginfo("db pool: %s, size: %d",m_pool_name.c_str(),(int)m_free_list.size());
	return 0;
}

/**
 * TODO 增加保护机制，把分配的连接加入一个队列，这样获取连接时，若没有空闲连接会等待
 * TODO 检查已经分配的连接多久没有返回，如果超过一定时间，则自动收回连接，主要是用户忘了释放连接
 * */
CDBConn* CDBPool::GetDBConn()
{
	m_free_notify.Lock();
	
	// 若空闲连接为空
	while(m_free_list.empty()){
		if(m_db_cur_conn_cnt >= m_db_max_conn_cnt){
			// 当前连接数，大于最大连接数时，等待其他用户释放
			m_free_notify.Wait();
		}else{
			// 当前连接数，小于最大值时，新增一个连接
			CDBConn* pDBConn = new CDBConn(this);
			int ret = pDBConn->Init();
			if(ret){
				// 初始化失败
				log("init DBConnection failed");
				delete pDBConn;
				m_free_notify.Unlock();
				return NULL;
			}else{
				// 初始化成功
				m_free_list.push_back(pDBConn);
				m_db_cur_conn_cnt++;
				log("new db connection: %s, conn_cnt: %d",m_pool_name.c_str(),m_db_cur_conn_cnt);
			}
		}
	}

	m_free_notify.Unlock();
}

void CDBPool::RelDBConn(CDBConn* pConn)
{

}

/// CDBManager
CDBManager* CDBManager::s_Instance = NULL;
CDBManager* CDBManager::Instance()
{
	if(!s_Instance)
	{
		s_Instance = new CDBManager();
		if(s_Instance->Init()){
			delete s_Instance;
			s_Instance = NULL;
		}
	}
	return s_Instance;
}
int CDBManager::Init()
{
	CConfigFileReader config_file("dbproxyserver.conf");
	char* db_instances = config_file.GetConfigName("DBInstances");
	printf("db_instances: %s\n",db_instances);
	if(!db_instances){
		log("not configure DBInstances");
		return 1;
	}
	char host[64];
	char port[64];
	char dbname[64];
	char username[64];
	char password[64];
	char maxconncnt[64];
	
	CStrExplode instances_name(db_instances,',');
	for(uint32_t i=0;i<instances_name.GetItemCnt();i++){
		char* pool_name = instances_name.GetItem(i);
		snprintf(host,64,"%s_host",pool_name);
		snprintf(port,64,"%s_port",pool_name);
		snprintf(dbname,64,"%s_dbname",pool_name);
		snprintf(username,64,"%s_username",pool_name);
		snprintf(password,64,"%s_password",pool_name);
		snprintf(maxconncnt,64,"%s_maxconncnt",pool_name);

		char* db_host = config_file.GetConfigName(host);
		char* str_db_port = config_file.GetConfigName(port);
		char* db_name = config_file.GetConfigName(dbname);
		char* db_username = config_file.GetConfigName(username);
		char* db_password = config_file.GetConfigName(password);
		char* str_maxconncnt = config_file.GetConfigName(maxconncnt);

		if(!db_host || !str_db_port || !db_name || !db_username || !db_password || !str_maxconncnt){
			log("not configure db instance: %s",pool_name);
			return 2;
		}
		int db_port = atoi(str_db_port);
		int db_maxconncnt = atoi(str_maxconncnt);
		CDBPool* pDBPool = new CDBPool(pool_name,db_host,db_port,db_username,db_password,db_name,db_maxconncnt);
		if(pDBPool->Init()){
			log("init db instance failed: %s",pool_name);
			return 3;
		}
		log("init db instance successed: %s",pool_name);
		m_dbpool_map.insert(make_pair(pool_name,pDBPool));
	}

	return 0;
}
