//
//  util.h
// 
#ifndef __util_h__
#define __util_h__

#include <stdio.h>
#include <string.h>
#include "../slog/slog_api.h"
#include <map>
#include <string>
#include <stdint.h>
#include <list>
#include <errno.h>

#include "StringUtils.h"
#include "Lock.h"

using namespace std;

#define LOG_MODULE_IM 		"default"

extern CSLog g_imlog;

#define __FILENAME__ (strrchr(__FILE__,'/') ? strrchr(__FILE__,'/')+1 : __FILE__)

#define log(fmt,args...) g_imlog.Error("<%s>\t<%d>\t<%s>," fmt,__FILENAME__,__LINE__,__FUNCTION__,##args)

#define loginfo(fmt,args...) g_imlog.Info("<%s>\t<%d>\t<%s>," fmt,__FILENAME__,__LINE__,__FUNCTION__,##args)

string int2string(uint32_t user_id);
uint32_t string2int(const string& value);

uint64_t get_tick_count();

#endif
