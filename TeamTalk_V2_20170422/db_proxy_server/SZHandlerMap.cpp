#include "SZHandlerMap.h"
#include "business/SZLogin.h"

SZHandlerMap* SZHandlerMap::s_Instance = NULL;
SZHandlerMap* SZHandlerMap::Instance()
{
	if(s_Instance == NULL)
	{
		s_Instance = new SZHandlerMap();
		s_Instance->Init();
	}
	return s_Instance;
}
void SZHandlerMap::Init()
{
	m_handler_map.insert(make_pair(2,DB_PROXY::doLogin));
}
pdu_handler_t SZHandlerMap::GetHandler(uint32_t pdu_type)
{
	HandlerMap_t::iterator it = m_handler_map.find(pdu_type);
	if(it != m_handler_map.end())
		return it->second;
	return NULL;
}
