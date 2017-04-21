#ifndef __netlib_h__
#define __netlib_h__

#include "ostype.h"

#define NETLIB_OPT_SET_CALLBACK 		1
#define NETLIB_OPT_SET_CALLBACK_DATA 	2
#define NETLIB_OPT_GET_REMOTE_IP 		3
#define NETLIB_OPT_GET_REMOTE_PORT  	4


#define NETLIB_MAX_SOCKET_BUF_SIZE 		(128*1024)

int netlib_listen(const char* ip,uint16_t port,callback_t callback,void* callback_data);
int netlib_connect(const char* ip,uint16_t port,callback_t callback,void* callback_data);

int netlib_send(int handle,void* buf,int len);
int netlib_recv(int handle,void* buf,int len);
int netlib_close(int handle);

int netlib_option(int handle,int opt,void* optval);

void netlib_eventloop(int timeout=1000);


#endif
