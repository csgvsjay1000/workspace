#include "Thread.h"

/// CThreadNotify
CThreadNotify::CThreadNotify()
{
	pthread_mutexattr_init(&m_mutexattr);
	pthread_mutexattr_settype(&m_mutexattr,PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&m_mutex,&m_mutexattr);

	pthread_cond_init(&m_cond,NULL);
}

CThreadNotify::~CThreadNotify()
{
	pthread_mutexattr_destroy(&m_mutexattr);
	pthread_mutex_destroy(&m_mutex);

	pthread_cond_destroy(&m_cond);
}
