#include <stdio.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

#define SERVER_PORT 12138
#define CON_QUEUE 20
#define MAX_DATA_SIZE 4096
#define MAX_EVENTS 500

struct NetPacketHeader
{
		    unsigned short      wDataSize;  ///< 数据包大小，包含封包头和封包数据大小
					 unsigned short      wOpcode;    ///< 操作码


};

#define NET_PACKET_DATA_SIZE 1024
struct NetPacket
{
		  	struct NetPacketHeader     Header;                         ///< 包头
				   	unsigned char       Data[NET_PACKET_DATA_SIZE];     ///< 数据


};
struct NetPacket_Test1 {
		    char name[20];
					char pass[20];
						    int age;

};

struct shared_use_st{
		int write;
			int fd;
				NetPacket packet;

};

int fd1[2],fd2[2];
struct REPORT {
		 pid_t pid;
		 	 char status;    // 'n' request new task, 'f' finsh the request

};

void run_child(){
		struct REPORT rep;
			char comm;
				pid_t pid = getpid();
					rep.pid = pid;
						int shmid;
							void *shm = NULL;
								shmid = shmget((key_t)1236,sizeof(shared_use_st),0666|IPC_CREAT);
									shm = shmat(shmid,NULL,0);
										struct shared_use_st *shared = NULL;
											shared = (struct shared_use_st *)shm;

											while(1){
														int ret = read(fd2[0],&comm,1);
																printf("ret: %d\n",ret);
																if(comm == 'e'){
																				exit(-1);
																						
																}else if(comm == 'c'){
																				printf("[%d] continue\n",pid);
																						
																}else if(comm == 'n'){
																				printf("[%d] process\n",pid);
																				if(shared->write != 0){
																									NetPacket packet = shared->packet;
																													NetPacket_Test1 *test1 = (NetPacket_Test1 *)(packet.Data);
																																	printf("%s\n",test1->name);
																																					printf("%s\n",test1->pass);
																																									printf("%d\n",test1->age);


																																												
																				}
																							
																						
																}

																		//rep.status = 'f';
																		//status//write(fd1[1],&rep,sizeof(rep));
																		//
																		//
											}

}

void InitProcessPoll(){
		pid_t pid = -1;
		for(int i=0;i<3;i++){
					pid = fork();
					if(pid == 0){
									run_child();
											
					}
						
		}

}

void AcceptConn(int sockfd,int epollfd);
void Handle(int clientfd);

struct shared_use_st *shared = NULL;

int main(int argc,char *agrv[]){
		printf("hello\n");
			pipe(fd2);
				InitProcessPoll();

					int shmid;
						void *shm = NULL;
							shmid = shmget((key_t)1236,sizeof(shared_use_st),0666|IPC_CREAT);
								shm = shmat(shmid,NULL,0);
									shared = (struct shared_use_st *)shm;
										
										struct sockaddr_in serverSockaddr;
											int sockfd;
												sockfd = socket(AF_INET,SOCK_STREAM,0);
													serverSockaddr.sin_family = AF_INET;
														serverSockaddr.sin_port = htons(SERVER_PORT);
															bzero(&(serverSockaddr.sin_zero),8);
																
																int on = 1;
																	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
																		bind(sockfd,(struct sockaddr *)&serverSockaddr,sizeof(struct sockaddr));
																			listen(sockfd,CON_QUEUE);

																				int epollfd;
																					struct epoll_event eventList[MAX_EVENTS];
																						epollfd = epoll_create(MAX_EVENTS);
																							struct epoll_event event;
																								event.events = EPOLLIN|EPOLLET;
																									event.data.fd = sockfd;
																										epoll_ctl(epollfd,EPOLL_CTL_ADD,sockfd,&event);

																										while(1){
																													int timeout = 300;
																															int ret = epoll_wait(epollfd,eventList,MAX_EVENTS,timeout);
																															if(ret == 0){
																																			continue;
																																					
																															}
																															for(int i=0;i<ret;i++){
																																if(eventList[i].data.fd == sockfd){
																																					AcceptConn(sockfd,epollfd);
																																								
																																}else{
																																					Handle(eventList[i].data.fd);
																																								
																																}
																																		
																															}

																																
																										}
																											close(epollfd);
																												close(sockfd);
																													return 0;

}

void AcceptConn(int sockfd,int epollfd){
		printf("accept new client\n");
			struct sockaddr_in sin;
				socklen_t len = sizeof(struct sockaddr_in);
					bzero(&sin,len);

						int confd = accept(sockfd,(struct sockaddr *)&sin,&len);

							struct epoll_event event;
								event.data.fd = confd;
									event.events = EPOLLIN|EPOLLET;
										epoll_ctl(epollfd,EPOLL_CTL_ADD,confd,&event);
											return;

}

void Handle(int clientfd){
		int recvLen = 0;
			char recvBuf[MAX_DATA_SIZE];
				memset(recvBuf,0,sizeof(recvBuf));
					char comm = 'n';

						NetPacket *netPacket_;
							netPacket_ = (NetPacket *)recvBuf;
								recvLen = recv(clientfd,(char *)recvBuf,sizeof(NetPacketHeader),0);

									recvLen = recv(clientfd,netPacket_->Data,netPacket_->Header.wDataSize-sizeof(struct NetPacketHeader),0);
										shared->packet = *netPacket_;
											shared->write = 1;
												shared->fd = clientfd;

													write(fd2[1],&comm,1);
														//commprintf("接收的数据:%s\n",recvBuf);
														//
														////recvBufNetPacket_Test1 *test1 = (NetPacket_Test1 *)(netPacket_->Data);
														////Dataprintf("%s\n",test1->name);
														////nameprintf("%s\n",test1->pass);
														////passprintf("%d\n",test1->age);
														//
														//
}
