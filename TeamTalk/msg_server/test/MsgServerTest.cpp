#include "netlib.h"
#include "util.h"
#include "MsgTest.h"

void test_connect_callback(void* callbackData,uint8_t msg,uint32_t handle,void* pParam)
{

	loginfo("netlib_connect  ");	
}
int main(){
	loginfo("MsgServerTest...");

	CMsgTest test;
	test.TestConnect();
//	int ret =  netlib_connect("127.0.0.1",8000,&test_connect_callback,NULL);

	while(1){
		sleep(1);
	}

	return 0;
}
