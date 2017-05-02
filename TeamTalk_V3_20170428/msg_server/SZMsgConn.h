#ifndef __SZMsgConn_h__
#define __SZMsgConn_h__

#include "SZBaseSocket.h"

class SZMsgConn : public SZBaseSocket
{
public:
	virtual void HandlePdu(SZPduBase* pPdu);	

	string GetLoginName(){return m_login_name;}

private:
	void _HandleLoginRequest(SZPduBase* pPdu);

private:
	string 		m_login_name;
};


#endif
