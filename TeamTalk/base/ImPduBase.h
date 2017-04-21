#ifndef __impdubase_h__
#define __impdubase_h__

#include "SimpleBuffer.h"

#define IM_PDU_HEADER_LEN 		16
#define IM_PDU_VERSION 			1

typedef struct{
	uint32_t 	length; 		//包长度  	4
	uint16_t 	version; 		//版本  	6
	uint16_t 	flag;  			//not use 	8
	uint16_t 	service_id; 			//	10
	uint16_t 	command_id; 			//  12
	uint16_t 	seq_num; 		//包序号 	14
	uint16_t 	reversed; 		//保留 	 	16
}PduHeader_t;

class CImPdu
{
public:
	CImPdu();
	~CImPdu(){};
	
	uint8_t* GetBuffer();
	uint32_t GetLength();
	uint8_t* GetBodyData();
	uint32_t GetBodyLength();

	int16_t GetVersion(){return m_pduHeader.version;}
	int16_t GetFlag(){return m_pduHeader.flag;}
	int16_t GetServiceId(){return m_pduHeader.service_id;}
	int16_t GetCommandId(){return m_pduHeader.command_id;}
	int16_t GetSeqNum(){return m_pduHeader.seq_num;}
	int16_t GetReversed(){return m_pduHeader.reversed;}

	void SetVersion(uint16_t version);
	void SetFlag(uint16_t flag);
	void SetServiceId(uint16_t service_id);
	void SetCommandId(uint16_t command_id);
	void SetError(uint16_t error);
	void SetSeqNum(uint16_t seq_num);
	void SetReversed(uint16_t reversed);

	void WriteHeader();
	static bool IsPduAvailable(uint8_t* buf,uint32_t len,uint32_t& pdu_len);
	static CImPdu* ReadPdu(uint8_t* buf,uint32_t len);
	void Write(uint8_t* buf,uint32_t len){m_simpleBuffer.Write(buf,len);}
	int ReadPduHeader(uint8_t* buf,uint32_t len);
	void SendMsg(const char* msg);

protected:
	CSimpleBuffer 	m_simpleBuffer;
	PduHeader_t 	m_pduHeader;

};


#endif
