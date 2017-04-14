#include "util.h"
#include "ConfigFileReader.h"
#include "netlib.h"
#include "MsgConn.h"

void msg_serv_callback(void* callbackData,uint8_t msg,uint32_t handle,void* pParam)
{
	if(msg == NETLIB_MSG_CONNECT)
	{
		
	}
	else
	{
		log("!!! error msg: %d",msg);
	}
}

int main(){
	CConfigFileReader config_file("msgserver.conf");
	loginfo("msg_server starting...");		
	
	char* listen_ip = config_file.GetConfigName("ListenIP");
	char* str_listen_port = config_file.GetConfigName("ListenPort");

	uint16_t listen_port = atoi(str_listen_port);
	netlib_listen(listen_ip,listen_port,msg_serv_callback,NULL);

	netlib_eventloop();

	return 0;
}
