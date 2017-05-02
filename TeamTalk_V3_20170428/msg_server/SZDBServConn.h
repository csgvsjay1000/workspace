#ifndef __SZDBServConn_h__
#define __SZDBServConn_h__

#include "SZBaseSocket.h"

class SZDBServConn : public SZBaseSocket
{
public:
	virtual void HandlePdu(SZPduBase* pPdu);

private:
	void _HandleLoginResponse(SZPduBase* pPdu);
};

void init_db_serv_conn();
SZDBServConn* get_db_serv_conn();

#endif
