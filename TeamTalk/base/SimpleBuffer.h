#ifndef __SimpleBuffer_h__
#define __SimpleBuffer_h__

#include <stdint.h>

class CSimpleBuffer
{
public:
	CSimpleBuffer();
	~CSimpleBuffer();
	
	uint8_t* GetBuffer(){return m_buffer;}
	uint32_t GetAllocSize() {return m_allocSize;}
	uint32_t GetWriteOffset() {return m_writeOffset;}

	void IncWriteOffset(uint32_t len){m_writeOffset += len;}
	void Extend(uint32_t len);
	uint32_t Write(void* buf,uint32_t len);
	uint32_t Read(void* buf,uint32_t len);

private:
	uint8_t* 	m_buffer;
	uint32_t  	m_allocSize;
	uint32_t 	m_writeOffset;
};

class CByteStream
{
public:
	CByteStream(uint8_t* buf,uint32_t len);

	static uint16_t ReadUint16(uint8_t* buf);
	static uint32_t ReadUint32(uint8_t* buf);
	
	static void WriteUint16(uint8_t* buf,uint16_t data);
	static void WriteUint32(uint8_t* buf,uint32_t data);

	void operator >> (uint16_t& data);
	void operator >> (uint32_t& data);

private:
	void _ReadByte(void* buf,uint32_t& len);

private:
	uint8_t* m_buf;
	uint32_t m_len;
	uint32_t m_pos;
};

#endif
