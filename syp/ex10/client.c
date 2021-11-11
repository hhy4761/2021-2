#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define MAXLINE 200000

int main (int argc, char *argv[]) {
		int n, cfd;
		struct hostent *h;
		struct sockaddr_in saddr;
		char buf[MAXLINE];
		char *host = argv[1];
		int port = atoi(argv[2]);
		
		if ((cfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
				printf("socket() failed.\n");
			   	exit(1);}
		if ((h = gethostbyname(host)) == NULL) {
				printf("invalid hostname %s\n", host);
			   	exit(2);
		}   
		
		memset((char *)&saddr, 0, sizeof(saddr));
		saddr.sin_family = AF_INET;
		memcpy((char *)&saddr.sin_addr.s_addr, (char *)h->h_addr, h->h_length);
		saddr.sin_port = htons(port);
		
		if (connect(cfd,(struct sockaddr *)&saddr,sizeof(saddr)) < 0) {
				printf("connect() failed.\n");
				exit(3);
		}
		
		while (1) {
				char cmd[60];
				size_t size;
				int fd1;

				scanf("%s",cmd);
				if(strcmp(cmd,"quit") ==0){
						break;
				}
				strcat(cmd,".txt");
				//write(cfd, cmd, strlen(cmd));
			   	fd1 = open(cmd,O_RDONLY);
				if(fd1<0){
						printf("there is no file\n");
						continue;
				}
				read(fd1, buf, sizeof(buf));
				
				write(cfd,cmd,strlen(cmd)); // file name
				//read(cfd,cmd,strlen(cmd));
				//write(1,cmd,strlen(cmd));
				sleep(2);
				write(cfd, buf, sizeof(buf)); // file contents
				close(fd1);
				write(cfd,"",0);
				//read(cfd, buf, n);
				//write(1,buf,n);
		}
		close(cfd);
}
