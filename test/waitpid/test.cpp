#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void wait4children(int signo)
{
	int status;
	while(waitpid(-1, &status, WNOHANG) > 0);  
	printf("wait4children\n");
}

int main(){
	int i;
	signal(SIGCHLD,wait4children);
	pid_t pid;
	for(i=0;i<100;i++){
		pid = fork();
		if(pid == 0)
			break;
	}

	if(pid>0)
	{
		printf("press Enter to exit...");
		getchar();
	}

	return 0;
}
