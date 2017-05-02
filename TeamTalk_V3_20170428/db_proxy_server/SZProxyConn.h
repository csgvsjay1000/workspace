#ifndef __SZProxyConn_h__
#define __SZProxyConn_h__

#include "SZBaseSocket.h"

class SZProxyConn : public SZBaseSocket
{
public:
	virtual void HandlePdu(SZPduBase* pPdu);	


private:
	void _HandleLoginRequest(SZPduBase* pPdu);

};


#endif
