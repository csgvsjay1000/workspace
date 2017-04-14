#ifndef __netlib_h__
#define __netlib_h__

#include "ostype.h"

int netlib_listen(const char* ip,uint16_t port,callback_t callback,void* callback_data);

void netlib_eventloop(int timeout=1000);

#endif
