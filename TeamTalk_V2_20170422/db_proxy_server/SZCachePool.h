#ifndef __SZCachePool_h__
#define __SZCachePool_h__

#include <stdlib.h>
#include <string>
#include <list>
#include <map>
#include "hiredis.h"
#include "SZThread.h"

using namespace std;

class SZCacheConn
{
public:
	SZCacheConn(const char* pool_name);
	int Init();
	
	const char* GetPoolName(){return m_pool_name.c_str();}
	string Get(string key);
	string Set(string key,string& value);
	//设置生存时间
	string Setex(string key,int timeout,string& value);
private:
	redisContext* 	m_pContext;
	string 			m_pool_name;
};

class SZCachePool
{
public:
	SZCachePool(const char* pool_name,int db_num,int max_conn_cnt);
	int Init();

	SZCacheConn* GetCacheConn();
	void RelCacheConn(SZCacheConn* pCacheConn);

private:
	string 	m_pool_name;
	int 	m_db_num;
	int 	m_max_conn_cnt;
	int 	m_cur_conn_cnt;
	list<SZCacheConn*> m_free_list;
	SZThreadNotify 	 m_free_notify;	
};

class SZCacheManager
{
public:
	static SZCacheManager* Instance();
	int Init();
	SZCacheConn* GetCacheConn(const char* pool_name);
	void RelCacheConn(SZCacheConn* pCacheConn);
private:
	SZCacheManager(){};
private:
	static SZCacheManager* 		s_Instance;
	map<string,SZCachePool*> 	m_cache_pool_map;
};

#endif
