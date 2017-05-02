#ifndef __SZSessionModel_h__
#define __SZSessionModel_h__

#include "SZPduBase.h"
#include "IM.BaseDefine.pb.h"

class SZSessionModel
{
public:
	static SZSessionModel* Instance();
	
	uint32_t GetSessionId(uint32_t nUserId,uint32_t nPeerId,uint32_t nType,bool isAll);
	uint32_t AddSession(uint32_t nUserId,uint32_t nPeerId,uint32_t nType);
private:
	SZSessionModel(){};

	static SZSessionModel* s_Instance;
};

#endif
