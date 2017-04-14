#include "Lock.h"

CLock::CLock()
{
	pthread_mutex_init(&m_mutex,NULL);	
}

CLock::~CLock()
{
	pthread_mutex_destroy(&m_mutex);
}

void CLock::Lock()
{
	pthread_mutex_lock(&m_mutex);
}

void CLock::Unlock()
{
	pthread_mutex_unlock(&m_mutex);
}

/// CRefObject
CRefObject::CRefObject()
{
	m_lock = NULL;
	m_refCount = 1;
}
void CRefObject::AddRef()
{
	if(m_lock)
	{
		m_lock->Lock();
		m_refCount++;
		m_lock->Unlock();
	}
	else
	{
		m_refCount++;
	}
}
void CRefObject::ReleaseRef()
{
	if(m_lock)
	{
		m_lock->Lock();
		m_refCount--;
		if(m_refCount <= 0)
		{
			delete this;
			return;
		}
		m_lock->Unlock();
	}
	else
	{
		m_refCount--;
		if(m_refCount <= 0)
		{
			delete this;
			return;
		}
	}
	
}
