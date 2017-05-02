#include "hiredis/hiredis.h"
#include <stdio.h>

int main(){
	redisContext* c = redisConnect("127.0.0.1",6379);
	if(c->err)
	{
		redisFree(c);
		printf("Connect to redisServer fail\n");
		return 0;
	}

	const char* command1 = "set stest1 value1";
	redisReply* r = (redisReply*)redisCommand(c,command1);
	if(NULL == r){
		redisFree(c);
		printf("Execut fail\n");
		return 0;
	}

	if(NULL == r)
	{
		redisFree(c);
	}

	r = (redisReply*)redisCommand(c,"get stest1");
	printf("%s\n",r->str);

	redisFree(c);

	return 0;
}
