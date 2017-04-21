#include "SZThreadPool.h"
#include <stdlib.h>

SZWorkerThread::SZWorkerThread()
{
	m_task_cnt = 0;
}
void* SZWorkerThread::StartRoutine(void* arg)
{
	SZWorkerThread* pThread = (SZWorkerThread*)arg;
	pThread->Execute();
	return NULL;
}
void SZWorkerThread::Start()
{
	pthread_create(&m_thread_id,NULL,StartRoutine,this);
}
void SZWorkerThread::Execute()
{
	while(true){
		m_threadNotify.Lock();
		while(m_task_list.empty()){
			m_threadNotify.Wait();
		}
		SZTask* pTask = m_task_list.front();
		m_task_list.pop_front();	
		m_threadNotify.Unlock();
		pTask->Run();
		delete pTask;
	}
}
void SZWorkerThread::PushTask(SZTask* pTask)
{
	m_threadNotify.Lock();
	m_task_list.push_back(pTask);
	m_threadNotify.Signal();
	m_threadNotify.Unlock();
}


SZThreadPool::SZThreadPool()
{
	m_workerSize = 0;
	m_workerList = NULL;
}

int SZThreadPool::Init(uint32_t worker_size)
{
	m_workerSize = worker_size;
	m_workerList = new SZWorkerThread[m_workerSize];
	if(!m_workerList)
		return 1;
	for(uint32_t i=0;i<m_workerSize;i++)
	{
		m_workerList[i].SetThreadIdx(i);
		m_workerList[i].Start();
	}	
	return 0;
}
void SZThreadPool::AddTask(SZTask* pTask)
{
	uint32_t idx = random()%m_workerSize;
	m_workerList[idx].PushTask(pTask);
}
void SZThreadPool::Destory()
{
	if(m_workerList)
		delete []m_workerList;
}

