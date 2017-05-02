#include "SZFunctionDefines.h"
#include <sstream>
#include <stdlib.h>

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
