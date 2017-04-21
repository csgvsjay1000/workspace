#include "SZEventDispatch.h"
#include <sys/epoll.h>
#include "SZHeaders.h"
#include "SZBaseSocket.h"

SZEventDispatch* SZEventDispatch::s_Instance = NULL;
SZEventDispatch* SZEventDispatch::Instance()
{
	if(s_Instance == NULL)
	{
		s_Instance = new SZEventDispatch();
	}
	return s_Instance;
}

SZEventDispatch::SZEventDispatch()
{
	m_epfd = epoll_create(1024);
}

SZEventDispatch::~SZEventDispatch()
{
	close(m_epfd);
}

void SZEventDispatch::AddEvent(int fd)
{
	struct epoll_event ev;
	ev.events = EPOLLIN | EPOLLOUT | EPOLLET;
	ev.data.fd = fd;
	epoll_ctl(m_epfd,EPOLL_CTL_ADD,fd,&ev);
}
void SZEventDispatch::RemoveEvent(int fd)
{
	epoll_ctl(m_epfd,EPOLL_CTL_DEL,fd,NULL);
}
void SZEventDispatch::StartDispatch(int timeout)
{
	struct epoll_event events[1024];
	int nfds = 0;
	while(true)
	{
		nfds = epoll_wait(m_epfd,events,1024,timeout);
		for(int i=0;i<nfds;i++)
		{
			int ev_fd = events[i].data.fd;
			SZBaseSocket* pSocket = FindBaseSocket(ev_fd);
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
		}
	}
}
