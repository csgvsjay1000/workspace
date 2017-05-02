#include "SZCachePool.h"
#include <string.h>

SZCacheConn::SZCacheConn(const char* pool_name)
{
	m_pContext = NULL;

}
int SZCacheConn::Init()
{
	struct timeval timeout = {0,200000};
	m_pContext = redisConnectWithTimeout("127.0.0.1",6379,timeout);
	if(!m_pContext || m_pContext->err){
		if(!m_pContext || m_pContext->errstr ){
			if(m_pContext){
				printf("redisConnect failed: %s\n",m_pContext->errstr);
				redisFree(m_pContext);
				m_pContext = NULL;
			}
			return 1;
		}
	}
	redisReply* reply = (redisReply*)redisCommand(m_pContext,"SELECT 1");
	if(reply && (reply->type == REDIS_REPLY_STATUS) && (strncmp(reply->str,"OK",2)==0)){
		freeReplyObject(reply);
		return 0;
	}else{
		printf("select cache db failed\n");
		return 2;
	}
	return 0;
}

string SZCacheConn::Get(string key)
{	
	string ret_value;
	redisReply* reply = (redisReply*)redisCommand(m_pContext,"GET %s",key.c_str());
	if(!reply){
			printf("redisCommand failed: %s\n",m_pContext->errstr);
			redisFree(m_pContext);
			m_pContext = NULL;
		return ret_value;
	}
	if(reply->type == REDIS_REPLY_STRING){
		ret_value.append(reply->str,reply->len);
	}
	freeReplyObject(reply);
	return ret_value;
}
string SZCacheConn::Set(string key,string& value)
{
	string ret_value;
	redisReply* reply = (redisReply*)redisCommand(m_pContext,"SET %s %s",key.c_str(),value.c_str());
	if(!reply){
			printf("redisCommand failed: %s\n",m_pContext->errstr);
			redisFree(m_pContext);
			m_pContext = NULL;
		return ret_value;
	}
	ret_value.append(reply->str,reply->len);
	freeReplyObject(reply);
	return ret_value;
}

string SZCacheConn::Setex(string key,int timeout,string& value)
{
	string ret_value;
	redisReply* reply = (redisReply*)redisCommand(m_pContext,"SET %s %d %s",key.c_str(),timeout,value.c_str());
	if(!reply){
			printf("redisCommand failed: %s\n",m_pContext->errstr);
			redisFree(m_pContext);
			m_pContext = NULL;
		return ret_value;
	}
	ret_value.append(reply->str,reply->len);
	freeReplyObject(reply);
	return ret_value;
}
	
SZCachePool::SZCachePool(const char* pool_name,int db_num,int max_conn_cnt)
{
	m_pool_name = pool_name;
	m_db_num = db_num;
	m_max_conn_cnt = max_conn_cnt;
	m_cur_conn_cnt = 2;
}
int SZCachePool::Init()
{
	for(int i=0;i<m_cur_conn_cnt;i++){
		SZCacheConn* pConn = new SZCacheConn(m_pool_name.c_str());
		if(pConn->Init()){
			delete pConn;
			return 1;
		}
		m_free_list.push_back(pConn);
	}
	printf("cache pool: %s, list size: %lu\n",m_pool_name.c_str(),m_free_list.size());

	return 0;
}

SZCacheConn* SZCachePool::GetCacheConn()
{
	m_free_notify.Lock();
	while(m_free_list.empty()){
		if(m_cur_conn_cnt >= m_max_conn_cnt){
			m_free_notify.Wait();
		}else{
			SZCacheConn* pCacheConn = new SZCacheConn(m_pool_name.c_str());
			int ret = pCacheConn->Init();
			if(ret){
				delete pCacheConn;
				m_free_notify.Unlock();
				return NULL;
			}else{
				m_free_list.push_back(pCacheConn);
				m_cur_conn_cnt++;
			}
		}
	}
	SZCacheConn* pConn = m_free_list.front();
	m_free_list.pop_front();
	m_free_notify.Unlock();
	return pConn;
}

void SZCachePool::RelCacheConn(SZCacheConn* pCacheConn)
{
	m_free_notify.Lock();
	list<SZCacheConn*>::iterator it = m_free_list.begin();
	for(;it!=m_free_list.end();it++){
		if(*it == pCacheConn){
			break;
		}
	}
	if(it == m_free_list.end()){
		m_free_list.push_back(pCacheConn);
	}
	m_free_notify.Signal();
	m_free_notify.Unlock();
}
SZCacheManager* SZCacheManager::s_Instance = NULL;
SZCacheManager* SZCacheManager::Instance()
{
	if(!s_Instance){
		s_Instance = new SZCacheManager();
		if(s_Instance->Init()){
			delete s_Instance;
			s_Instance = NULL;
		}
	}
	return s_Instance;
}
int SZCacheManager::Init()
{
	SZCachePool* pool_1 = new SZCachePool("unread",1,16);
	SZCachePool* pool_2 = new SZCachePool("group_set",1,16);
	SZCachePool* pool_3 = new SZCachePool("token",1,16);
	SZCachePool* pool_4 = new SZCachePool("sync",2,1);
	SZCachePool* pool_5 = new SZCachePool("group_member",1,16);
	
	m_cache_pool_map.insert(make_pair("unread",pool_1));
	m_cache_pool_map.insert(make_pair("group_set",pool_2));
	m_cache_pool_map.insert(make_pair("token",pool_3));
	m_cache_pool_map.insert(make_pair("sync",pool_4));
	m_cache_pool_map.insert(make_pair("group_member",pool_5));
	return 0;
}
SZCacheConn* SZCacheManager::GetCacheConn(const char* pool_name)
{
	map<string,SZCachePool*>::iterator it = m_cache_pool_map.find(pool_name);
	if(it != m_cache_pool_map.end()){
		return it->second->GetCacheConn();
	}else{
		return NULL;
	}

}
void SZCacheManager::RelCacheConn(SZCacheConn* pCacheConn)
{
	if(!pCacheConn)
		return;
	map<string,SZCachePool*>::iterator it = m_cache_pool_map.find(pCacheConn->GetPoolName());
	if(it != m_cache_pool_map.end()){
		return it->second->RelCacheConn(pCacheConn);
	}
}
