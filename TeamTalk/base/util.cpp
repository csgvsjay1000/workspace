#include "util.h"
#include <sstream>
#include <stdlib.h>
#include <sys/time.h>

CSLog g_imlog = CSLog(LOG_MODULE_IM);

//CSLog g_calog = CSLog("ca");
uint32_t string2int(const string& value)
{
	return (uint32_t)atoi(value.c_str());
}
string int2string(uint32_t user_id)
{
	stringstream ss;
	ss<<user_id;
	return ss.str();
}

uint64_t get_tick_count()
{
	struct timeval tval;
	uint64_t ret_tick;
	gettimeofday(&tval,NULL);
	ret_tick = tval.tv_sec*1000L + tval.tv_usec/1000L;
	return ret_tick;
}
