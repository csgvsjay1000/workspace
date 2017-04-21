#include "MsgTest.h"
#include "util.h"
#include "imconn.h"

void connect_callback(void* callbackData,uint8_t msg,uint32_t handle,void* pParam)
{

	loginfo("netlib_connect  ");	
}

void CMsgTest::TestConnect()
{
	int ret =  netlib_connect("127.0.0.1",8000,&connect_callback,NULL);
	loginfo("netlib_connect ret=%d ",ret);	
	CImConn *pImConn = new CImConn();
	pImConn->OnConnect(ret);
	CImPdu *pPdu = new CImPdu();

}
