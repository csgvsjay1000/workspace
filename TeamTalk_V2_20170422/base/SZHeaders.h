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
using namespace __gnu_cxx;
using namespace std;

typedef void* (*callback_t)(void* pParam);

#endif
