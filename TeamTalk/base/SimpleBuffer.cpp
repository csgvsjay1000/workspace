#include "SimpleBuffer.h"
#include <string.h>

CSimpleBuffer::CSimpleBuffer()
{
	m_buffer = NULL;
	m_allocSize = 0;
	m_writeOffset = 0;
}
CSimpleBuffer::~CSimpleBuffer()
{
	m_allocSize = 0;
	m_writeOffset = 0;
	if(m_buffer)
	{
		free(m_buffer);
		m_buffer = NULL;
	}
}

void CSimpleBuffer::Extend(uint32_t len)
{
	m_allocSize = m_writeOffset + len;
	m_allocSize += m_allocSize >> 2;
	uint8_t* new_buf = (uint8_t *)realloc(m_buffer,m_allocSize);
	m_buffer = new_buf;
}

uint32_t CSimpleBuffer::Write(void* buf,uint32_t len)
{
	if(m_writeOffset + len > m_allocSize)
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

uint32_t CSimpleBuffer::Read(void* buf,uint32_t len)
{
	if(len > m_writeOffset)
		len = m_writeOffset;
	if(buf)
		memcpy(buf,m_buffer,len);
	m_writeOffset -= len;
	memmove(m_buffer,m_buffer+len,m_writeOffset);
	return len;
}
	
/// CByteStream
CByteStream::CByteStream(uint8_t* buf,uint32_t len)
{
	m_buf = buf;
	m_len = len;
	m_pos = 0;
}

uint16_t CByteStream::ReadUint16(uint8_t* buf)
{
	uint16_t data = (buf[0] << 8) | buf[1];
	return data;
}

uint32_t CByteStream::ReadUint32(uint8_t* buf)
{
	uint32_t data = (buf[0] << 24) | (buf[1] << 16) | (buf[2]<<8) | (buf[3]);
	return data;
}

void CByteStream::WriteUint16(uint8_t* buf,uint16_t data)
{
	buf[0] = static_cast<uint8_t>(data >> 8);
	buf[1] = static_cast<uint8_t>(data & 0xFF);
}

void CByteStream::WriteUint32(uint8_t* buf,uint32_t data)
{
	buf[0] = static_cast<uint8_t>(data >> 24);
	buf[1] = static_cast<uint8_t>((data >> 16) & 0xFF);
	buf[2] = static_cast<uint8_t>((data >> 8) & 0xFF);
	buf[3] = static_cast<uint8_t>(data & 0xFF);
}

void CByteStream::operator >> (uint16_t& data)
{
	uint8_t buf[2];
	_ReadByte(buf,2);
	data = (buf[0]<<8)|buf[1];
}

void CByteStream::operator >> (uint32_t& data)
{
	uint8_t buf[4];
	_ReadByte(buf,4);
	data = (buf[0]<<24)|(buf[1]<<16)|(buf[2]<<8)|(buf[3]);
}

void CByteStream::_ReadByte(void* buf,uint32_t& len)
{
	if(m_pos+len>m_len)
	{
		return;
	}
	memcpy(buf,m_buf+m_pos,len);
	m_pos += len;
}
