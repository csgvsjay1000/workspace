#ifndef __szmsg_conn_h__
#define __szmsg_conn_h__

#include "SZBaseSocket.h"

class SZMsgConn : public SZBaseSocket
{
public:	
	virtual void HandlePdu(SZPduBase* pPdu);
};

#endif
