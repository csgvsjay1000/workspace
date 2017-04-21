#ifndef __MsgConn_h__
#define __MsgConn_h__

#include "imconn.h"

typedef struct{
	uint32_t msg_id;
	uint32_t from_id;
	uint64_t timestamp;
}msg_ack_t;

class CMsgConn : public CImConn
{
public:
	CMsgConn(){};
	virtual ~CMsgConn(){};
	virtual void OnConnect(int handle);
	virtual void HandlePdu(CImPdu* pPdu);
private:
	void _HandleLoginRequest(CImPdu* pPdu);

};

#endif
