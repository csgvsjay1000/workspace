#ifndef __SZMessageModel_h__
#define __SZMessageModel_h__

#include "SZPduBase.h"
#include "IM.BaseDefine.pb.h"

#include <string>

using namespace std;

class SZMessageModel
{
public:
	static SZMessageModel* Instance();
	bool SendMessage(uint32_t nRelateId,uint32_t nFromId,uint32_t nToId,IM::BaseDefine::MsgType nMsgType,uint32_t nCreateTime,uint32_t nMsgId,string& strMsgContent);
private:
	SZMessageModel(){};
	static SZMessageModel* 	s_Instance;
};

#endif
