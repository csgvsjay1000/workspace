#include "SZPduBase.h"
#include "SZSimpleBuffer.h"
#include <string.h>
#include <stdio.h>

SZPduBase::SZPduBase()
{
	memset(&m_pduHeader,0,sizeof(m_pduHeader));
}

void SZPduBase::WriteHeader()
{
	uint8_t* buf = GetBuffer();
	SZByteStream::WriteUint32(buf,m_pduHeader.length);
}
void SZPduBase::SetServiceId(uint16_t service_id)
{
	uint8_t* buf = GetBuffer();
	SZByteStream::WriteUint16(buf+4,service_id);
}
void SZPduBase::SetCommandId(uint16_t command_id)
{
	uint8_t* buf = GetBuffer();
	SZByteStream::WriteUint16(buf+6,command_id);
}

void SZPduBase::SetMsg(const char* msg)
{
	uint32_t msg_size = strlen(msg)+1;
	m_simpleBuffer.Read(NULL,m_simpleBuffer.GetWriteOffset());
	m_simpleBuffer.Write(NULL,sizeof(PduHeader_t));
	m_simpleBuffer.Write((void*)msg,msg_size);
	m_pduHeader.length = msg_size + sizeof(PduHeader_t);
	WriteHeader();
}
void SZPduBase::SetPBMsg(const google::protobuf::MessageLite* msg)
{
	m_simpleBuffer.Read(NULL,m_simpleBuffer.GetWriteOffset());
	m_simpleBuffer.Write(NULL,sizeof(PduHeader_t));
	uint32_t msg_size = msg->ByteSize();
	uint8_t* szData = new uint8_t[msg_size];
	if(!msg->SerializeToArray(szData,msg_size)){
		printf("SZPduBase::SetPBMsg SerializeToArray failed\n");
	}
	m_simpleBuffer.Write(szData,msg_size);
	delete []szData;
	m_pduHeader.length = msg_size + sizeof(PduHeader_t);
	WriteHeader();
}

int SZPduBase::ReadHeader(uint8_t* buf,uint32_t len)
{
	SZByteStream bs(buf,len);
	bs >> m_pduHeader.length;
	bs >> m_pduHeader.service_id;
	bs >> m_pduHeader.command_id;
	return 0;	
}

SZPduBase* SZPduBase::ReadPdu(uint8_t* buf,uint32_t len)
{
	uint32_t pdu_len = 0;
	pdu_len = SZByteStream::ReadUint32(buf);
	SZPduBase* pPdu = new SZPduBase();
	pPdu->Write(buf,pdu_len);
	pPdu->ReadHeader(buf,sizeof(PduHeader_t));
	return pPdu;	
}

uint8_t* SZPduBase::GetBodyData()
{
	return m_simpleBuffer.GetBuffer() + sizeof(PduHeader_t);
}
uint32_t SZPduBase::GetBodyLength()
{
	return m_simpleBuffer.GetWriteOffset()-sizeof(PduHeader_t);
}
