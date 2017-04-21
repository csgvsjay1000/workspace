#ifndef __SZThreadPool_h__
#define __SZThreadPool_h__

#include <pthread.h>
#include <list>
#include <stdint.h>
#include "SZTask.h"
#include "SZThread.h"

using namespace std;

class SZWorkerThread
{
public:
	SZWorkerThread();
	static void* StartRoutine(void* arg);
	void Start();
	void Execute();
	void PushTask(SZTask* pTask);

	void SetThreadIdx(uint32_t idx){m_thread_idx = idx;}

private:
	uint32_t 		m_thread_idx;
	uint32_t 		m_task_cnt;
	pthread_t 		m_thread_id;
	list<SZTask*> 	m_task_list;
	SZThreadNotify 	m_threadNotify;
};

class SZThreadPool
{
public:
	SZThreadPool();
	int Init(uint32_t worker_size);
	void AddTask(SZTask* pTask);
	void Destory();
private:
	uint32_t 		m_workerSize;
	SZWorkerThread* m_workerList;
};

#endif
