#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>
#define MAXLINE 200000

int main (int argc, char *argv[]) {
		int n, listenfd, connfd, caddrlen;
		struct hostent *h;
		struct sockaddr_in saddr, caddr;
		char buf[MAXLINE];
		int port = atoi(argv[1]);
		int cnt = 0;
		int fd1;	
		if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
				printf("socket() failed.\n");
				exit(1);
		}
		
		memset((char *)&saddr, 0, sizeof(saddr));
		saddr.sin_family = AF_INET;
		saddr.sin_addr.s_addr = htonl(INADDR_ANY);
		saddr.sin_port = htons(port);
	 	
		if (bind(listenfd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0) {
				printf("bind() failed.\n");exit(2);
		}
		
		if (listen(listenfd, 5) < 0) {
				printf("listen() failed.\n");
				exit(3);
		}
		
		while (1) {
				caddrlen = sizeof(caddr);
				if ((connfd = accept(listenfd, (struct sockaddr *)&caddr,(socklen_t *)&caddrlen)) < 0) {
						printf ("accept() failed.\n");
						continue;
				}
			// echo
				while ((n = read(connfd, buf, sizeof(buf))) > 0) {
						//if(buf == NULL)
						//		continue;
				//		if(cnt%2==0){
							fd1 = open(buf,O_CREAT|O_RDWR);
							printf("\nfile name:%s\n",buf);
							write(connfd,buf,sizeof(buf));
							n = read(connfd,buf, sizeof(buf));
							printf("file contents:%s",buf);
							printf("got %d bytes from client.\n",n);
							write(fd1,buf,sizeof(buf));
							read(connfd,buf,sizeof(buf));
							
				//		}
				/*		else{
							write(fd1,buf,sizeof(buf));
							close(fd1);
							printf("file contents: %s",buf);
							write(connfd,buf,80);
							cnt++;
						}
				*/		/*		int fd1 = open(buf,O_CREAT);
						printf("file name: %s",buf);
						read(connfd,buf,sizeof(buf));
						printf("file contents: %s",buf);
						write(fd1, buf, sizeof(buf));
						close(fd1);
						printf ("got %d bytes from client.\n", n);
				*/}
				printf("connection terminated.\n");
				close(connfd);
		}
}
