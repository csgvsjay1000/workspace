#include "EventDispatch.h"
#include <sys/epoll.h>
#include "BaseSocket.h"

CEventDispatch* CEventDispatch::s_Instance = NULL;
CEventDispatch* CEventDispatch::Instance()
{
	if(s_Instance == NULL)
	{
		s_Instance = new CEventDispatch();
	}
	return s_Instance;
}

CEventDispatch::CEventDispatch()
{
	m_epfd = epoll_create(1024);
	running = false;
}

CEventDispatch::~CEventDispatch()
{
	close(m_epfd);
}

void CEventDispatch::AddEvent(int fd)
{
	struct epoll_event ev;
	ev.events = EPOLLIN | EPOLLOUT | EPOLLET | EPOLLPRI | EPOLLERR | EPOLLHUP;
	ev.data.fd = fd;
	if(epoll_ctl(m_epfd,EPOLL_CTL_ADD,fd,&ev) != 0)
	{
		log("epoll_ctl() failed, errno=%d",errno);
	}
}

void CEventDispatch::RemoveEvent(int fd)
{
	if(epoll_ctl(m_epfd,EPOLL_CTL_DEL,fd,NULL) != 0)
	{
		log("epoll_ctl() failed, errno=%d",errno);
	}	
}

void CEventDispatch::StartDispatch(int timeout)
{
	struct epoll_event events[1024];
	int nfds = 0;
	if(running)
		return;
	running = true;
	while(running){
		nfds = epoll_wait(m_epfd,events,1024,timeout);
		for(int i=0; i<nfds; i++)
		{
			int ev_fd = events[i].data.fd;
			CBaseSocket* pSocket = FindBaseSocket(ev_fd);
			if(!pSocket)
				continue;
			if(events[i].events & EPOLLIN)
			{
				pSocket->OnRead();
			}

			if(events[i].events & EPOLLOUT)
			{
				pSocket->OnWrite();
			}

			if(events[i].events & (EPOLLPRI | EPOLLERR | EPOLLHUP))
			{
				pSocket->OnClose();
			}

			pSocket->ReleaseRef();
		}
	}
}
