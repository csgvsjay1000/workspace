#ifndef __szevent_dispatch_h__
#define __szevent_dispatch_h__

#include "SZHeaders.h"
#include <list>

class SZEventDispatch
{
public:
	SZEventDispatch();
	~SZEventDispatch();
	void AddEvent(int fd);
	void RemoveEvent(int fd);
	void StartDispatch(int timeout = 300);
	void AddLoop(callback_t callback,void* user_data);

	static SZEventDispatch* Instance();

private:
	int 	m_epfd;
	static SZEventDispatch* s_Instance;
private:
	void _CheckLoop();
	typedef struct {
		callback_t 	callback;
		void* 		user_data;
		uint64_t 	interval;
		uint64_t 	next_tick;
	}TimerItem;
	list<TimerItem*> 	m_loop_list;
};

#endif
