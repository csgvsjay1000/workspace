//
// 字符串处理类
//
#ifndef __STRINGUTILS_H__
#define __STRINGUTILS_H__

#include <stdint.h>

class CStrExplode
{
public:
	CStrExplode(char* str,char seperator);
	~CStrExplode();
	char* GetItem(uint32_t idx){return m_item_list[idx];}
	uint32_t GetItemCnt(){return m_item_cnt;}
private:
	uint32_t 		m_item_cnt;
	char** 			m_item_list;
};

#endif
