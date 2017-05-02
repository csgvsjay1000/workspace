#ifndef __SZPduBase_h__
#define __SZPduBase_h__

#include "SZSimpleBuffer.h"
#include <google/protobuf/message_lite.h>

typedef struct{
	uint32_t 		length;
	uint16_t 		service_id;
	uint16_t 		command_id;
}PduHeader_t;

class SZPduBase
{
public:
	SZPduBase();
	uint8_t* GetBuffer(){return m_simpleBuffer.GetBuffer();}
	uint32_t GetLength(){return m_simpleBuffer.GetWriteOffset();}
	uint8_t* GetBodyData();
	uint32_t GetBodyLength();
	
	uint16_t GetServiceId(){return m_pduHeader.service_id;}
	uint16_t GetCommandId(){return m_pduHeader.command_id;}

	void SetServiceId(uint16_t service_id);
	void SetCommandId(uint16_t command_id);

	void WriteHeader();
	int ReadHeader(uint8_t* buf,uint32_t len);
	void SetMsg(const char* msg);
	void SetPBMsg(const google::protobuf::MessageLite* msg);
	void Write(uint8_t* buf,uint32_t len){m_simpleBuffer.Write((void*)buf,len);}

	static SZPduBase* ReadPdu(uint8_t* buf,uint32_t len);

private:
	SZSimpleBuffer 	m_simpleBuffer;
	PduHeader_t 	m_pduHeader;
};

#endif
