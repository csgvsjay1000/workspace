#ifndef __EventDispatch_h__
#define __EventDispatch_h__

#include "ostype.h"
#include "util.h"

class CEventDispatch:public CRefObject
{
public:
	CEventDispatch();
	~CEventDispatch();
	void AddEvent(int socket);
	void RemoveEvent(int socket);
	void StartDispatch(int timeout=300);

	static CEventDispatch* Instance();

private:
	int 	m_epfd;
	static CEventDispatch* s_Instance;
	bool 	running;
};

#endif
