#include "ImPduBase.h"

CImPdu::CImPdu()
{
	m_pduHeader.version = IM_PDU_VERSION;
	m_pduHeader.flag = 0;
	m_pduHeader.service_id= 0;
	m_pduHeader.command_id = 0;
	m_pduHeader.seq_num = 0;
	m_pduHeader.reversed = 0;
}

bool CImPdu::IsPduAvailable(uint8_t* buf,uint32_t len,uint32_t& pdu_len)
{
	if(len < IM_PDU_HEADER_LEN)
		return false;
	pdu_len = CByteStream::ReadUint16(buf);
	if(pdu_len>len)
		return false;
	if(pdu_len == 0)
		return false;
	return true;
}

int CImConn::ReadPduHeader(uint8_t* buf,uint32_t len)
{
	if(len < IM_PDU_HEADER_LEN || !buf)
		return -1;
	CByteStream is(buf,len);
	is >> m_pduHeader.length;
	is >> m_pduHeader.version;
	is >> m_pduHeader.flag;
	is >> m_pduHeader.service_id;
	is >> m_pduHeader.command_id;
	is >> m_pduHeader.seq_num;
	is >> m_pduHeader.reversed;
	return 0;
}

CImPdu* CImPdu::ReadPdu(uint8_t* buf,uint32_t len)
{
	uint32_t pdu_len = 0;
	if(!IsPduAvailable(buf,len,pdu_len))
		return NULL;
	CImPdu *pPdu = new CImPdu();
	pPdu->Write(buf,len);
	pPdu->ReadPduHeader(buf,IM_PDU_HEADER_LEN);
	return pPdu;
}

uint8_t* CImPdu::GetBuffer()
{
	return m_simpleBuffer.GetBuffer();
}

uint32_t  CImPdu::GetLength()
{
	return m_simpleBuffer.GetWriteOffset();
}

uint8_t*  CImPdu::GetBodyData()
{
	return m_simpleBuffer.GetBuffer()+sizeof(PduHeader_t);
}

uint32_t  CImPdu::GetBodyLength()
{
	uint32_t body_length = 0;
	body_length = m_simpleBuffer.GetWriteOffset() - sizeof(PduHeader_t);
	return body_length;
}

void CImPdu::SetVersion(uint16_t version)
{
	uint8_t* buf = GetBuffer();
	CByteStream::WriteUint16(buf+4,version);
}

void CImPdu::SetFlag(uint16_t flag)
{
	uint8_t* buf = GetBuffer();
	CByteStream::WriteUint16(buf+6,version);
}

void CImPdu::SetServiceId(uint16_t service_id)
{
	uint8_t* buf = GetBuffer();
	CByteStream::WriteUint16(buf+8,version);
}

void CImPdu::SetCommandId(uint16_t command_id)
{
	uint8_t* buf = GetBuffer();
	CByteStream::WriteUint16(buf+10,version);
}
void CImPdu::SetError(uint16_t error);
{
}
void CImPdu::SetSeqNum(uint16_t seq_num);
{
	uint8_t* buf = GetBuffer();
	CByteStream::WriteUint16(buf+12,version);
}
void CImPdu::SetReversed(uint16_t reversed);
{
	uint8_t* buf = GetBuffer();
	CByteStream::WriteUint16(buf+14,version);
}
void CImPdu::WriteHeader()
{
	uint8_t* buf = GetBuffer();

	CByteStream::WriteUint32(buf,GetLength());
	CByteStream::WriteUint16(buf+4,m_pduHeader.version);
	CByteStream::WriteUint16(buf+6,m_pduHeader.flag);
	CByteStream::WriteUint16(buf+8,m_pduHeader.service_id);
	CByteStream::WriteUint16(buf+10,m_pduHeader.command_id);
	CByteStream::WriteUint16(buf+12,m_pduHeader.seq_num);
	CByteStream::WriteUint16(buf+14,m_pduHeader.reversed);
}
