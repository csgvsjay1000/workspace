#ifndef __base_lock__
#define __base_lock__

#include <pthread.h>

class CLock{
public:
	CLock();
	~CLock();
    void Lock();
	void Unlock();

private:
	pthread_mutex_t m_mutex;
};

class CRefObject
{
public:
	CRefObject();
	void AddRef();
	void ReleaseRef();
	void SetLock(CLock* lock){m_lock = lock;}

private:
	CLock* 	m_lock;
	int 	m_refCount;
};

#endif
