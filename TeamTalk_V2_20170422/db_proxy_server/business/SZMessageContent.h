#ifndef __SZMessageContent_h__
#define __SZMessageContent_h__

#include "SZPduBase.h"

namespace DB_PROXY{
void sendMessage(SZPduBase* pPdu,uint32_t conn_uuid);
};

#endif
