#ifndef __SZLogin_h__
#define __SZLogin_h__

#include "SZPduBase.h"

namespace DB_PROXY{
void doLogin(SZPduBase* pPdu,uint32_t conn_uuid);
};

#endif
