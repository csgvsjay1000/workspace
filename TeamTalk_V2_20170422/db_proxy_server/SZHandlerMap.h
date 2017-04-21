#ifndef __SZHandlerMap_h__
#define __SZHandlerMap_h__

#include <map>
#include "SZProxyTask.h"
using namespace std;
typedef map<uint32_t,pdu_handler_t> HandlerMap_t;

class SZHandlerMap
{
public:
	//virtual ~SZHandlerMap();
	static SZHandlerMap* Instance();
	void Init();
	pdu_handler_t GetHandler(uint32_t pdu_type);

private:
	//SZHandlerMap();
	static SZHandlerMap* s_Instance;
	HandlerMap_t 	m_handler_map;
};

#endif
