#include "SZBaseSocket.h"
#include "SZEventDispatch.h"

int main()
{
	printf("server start...\n");

	SZBaseSocket socket;
	int listenFd = socket.Listen("127.0.0.1",8000);
	SZEventDispatch::Instance()->StartDispatch();
	printf("server stop...\n");
	
	return 0;
}
