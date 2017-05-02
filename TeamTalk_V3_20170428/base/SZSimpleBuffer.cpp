#include "SZSimpleBuffer.h"
#include "SZHeaders.h"

SZSimpleBuffer::SZSimpleBuffer()
{
	m_buffer = NULL;
	m_allocSize = 0;
	m_writeOffset = 0;
}
SZSimpleBuffer::~SZSimpleBuffer()
{
	free(m_buffer);
	m_buffer = NULL;
}
void SZSimpleBuffer::Extend(uint32_t len)
{
	m_allocSize = m_writeOffset + len;
	m_allocSize += m_allocSize>>2;
	uint8_t* buf_new = (uint8_t*)realloc(m_buffer,m_allocSize);
	m_buffer = buf_new;
}
uint32_t SZSimpleBuffer::Write(void* buf,uint32_t len)
{
	if(m_writeOffset+len > m_allocSize)
	{
		Extend(len);
	}
	if(buf)
	{
		memcpy(m_buffer+m_writeOffset,buf,len);
	}
	m_writeOffset += len;
	return len;
}
uint32_t SZSimpleBuffer::Read(void* buf,uint32_t len)
{
	if(len > m_writeOffset)
	{
		len = m_writeOffset;
	}
	if(buf)
	{
		memcpy(buf,m_buffer,len);
	}
	m_writeOffset -= len;
	memmove(m_buffer,m_buffer+len,m_writeOffset);
	return len;
}
uint16_t SZByteStream::ReadUint16(uint8_t* buf)
{
	uint32_t data = (buf[0]<<8)|(buf[1]);
	return data;
}
uint32_t SZByteStream::ReadUint32(uint8_t* buf)
{
	uint32_t data = (buf[0]<<24)|(buf[1]<<16)|(buf[2]<<8)|(buf[3]);
	return data;
}

void SZByteStream::WriteUint16(uint8_t* buf,uint16_t data)
{
	buf[0] = static_cast<uint8_t>((data >>8 )&0xFF);
	buf[1] = static_cast<uint8_t>((data )&0xFF);
}
void SZByteStream::WriteUint32(uint8_t* buf,uint32_t data)
{
	buf[0] = static_cast<uint8_t>(data >> 24);
	buf[1] = static_cast<uint8_t>((data >> 16)&0xFF);
	buf[2] = static_cast<uint8_t>((data >>8 )&0xFF);
	buf[3] = static_cast<uint8_t>((data )&0xFF);
}

SZByteStream::SZByteStream(uint8_t* buf,uint32_t len)
{
	m_pBuf = buf;
	m_len = len;
	m_pos = 0;
}

void SZByteStream::_ReadByte(void* buf,uint32_t len)
{
	memcpy(buf,m_pBuf+m_pos,len);
	m_pos += len;
}

void SZByteStream::operator >> (uint32_t& data)
{
	uint8_t buf[4];
	_ReadByte(buf,4);
	data = (buf[0]<<24)|(buf[1]<<16)|(buf[2]<<8)|(buf[3]);
}

void SZByteStream::operator >> (uint16_t& data)
{
	uint8_t buf[2];
	_ReadByte(buf,2);
	data = (buf[0]<<8)|(buf[1]);
}

