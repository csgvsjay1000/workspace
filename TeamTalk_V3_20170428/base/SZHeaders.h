#ifndef __szheaders_h__
#define __szheaders_h__

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdint.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <ext/hash_map>


#include "SZFunctionDefines.h"

using namespace __gnu_cxx;
using namespace std;

typedef void* (*callback_t)(void* pParam);

#ifdef _DEBUG_
	#define log(fmt,args...)printf(fmt"\n",##args);
	#define loginfo(fmt,args...)printf(fmt"\n",##args);
#else
	#define log(fmt,args...){};
	#define loginfo(fmt,args...){};
#endif

#endif
