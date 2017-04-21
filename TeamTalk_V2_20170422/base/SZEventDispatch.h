#ifndef __szevent_dispatch_h__
#define __szevent_dispatch_h__

class SZEventDispatch
{
public:
	SZEventDispatch();
	~SZEventDispatch();
	void AddEvent(int fd);
	void RemoveEvent(int fd);
	void StartDispatch(int timeout = 300);

	static SZEventDispatch* Instance();

private:
	int 	m_epfd;
	static SZEventDispatch* s_Instance;
};

#endif
