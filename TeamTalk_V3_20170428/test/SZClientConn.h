#ifndef __szclient_conn_h__
#define __szclient_conn_h__

#include "SZBaseSocket.h"

class SZClientConn : public SZBaseSocket
{
public:
	virtual void HandlePdu(SZPduBase* pPdu);
	void OnConfirm();
};
#endif
