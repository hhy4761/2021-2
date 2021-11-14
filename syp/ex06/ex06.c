#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
   	unsigned int pid;
	time_t t;
	struct tm *tm;	
	int fd;
	char *argv[3];
	char buf[512];
	int fd0, fd1, fd2;

	pid = fork();
	
	if(pid == -1) return -1;
	if(pid != 0)
		exit(0);
	if(setsid() < 0)
		exit(0);
	if(chdir("/") < 0)
		exit(0);

	fd = open("./crontab", O_RDWR);
    
	umask(0);

	close(0);
	close(1);
	close(2);

	fd0 = open("/dev/null", O_RDWR);
	fd1 = open("/dev/null", O_RDWR);
	fd2 = open("/dev/null", O_RDWR);

	t = time(NULL);
	tm = localtime(&t);
	while (1)
	{
		buf[0] = '\0';
		int n = read(fd,buf,sizeof(buf));
		if (n==0){
			printf("Empty file");
			exit(1);
		}
		char *pos = buf;
		char *token;

		close(fd);
		fd = open("./crontab",O_RDWR);
		
		for(int i=0;i<3;i++){
			token = strtok_r(pos," ",&pos);
			argv[i] = token;
		}
		
		int min = -1;
		int hour = -1;
		if (strcmp(argv[0],"*")!=0)
			min = atoi(argv[0]);
		if (strcmp(argv[1],"*")!=0)
			hour = atoi(argv[1]);
		
		t = time(NULL);
		tm = localtime(&t);
		
		if(min==-1){
			if (hour == -1){
				pid_t pid;
				pid = fork();
		
				if(pid==0){
					execl("/bin/sh", "/bin/sh", "-c", argv[2], (char*) NULL);
					exit(0);
				}

				else{
					wait(NULL);
				}
				sleep(60);
			}
			else if(hour == tm->tm_hour){
				pid_t pid;
				pid = fork();
		
				if(pid==0){
					execl("/bin/sh", "/bin/sh", "-c", argv[2], (char*) NULL);
					exit(0);
				}
			
				else{
					wait(NULL);
				}
				sleep(60);
			}
		}
		else{
			if(hour == -1){
				if(min == tm->tm_min){
					pid_t pid;
					pid = fork();
			
					if(pid==0){
						execl("/bin/sh", "/bin/sh", "-c", argv[2], (char*) NULL);
						exit(0);
					}
				
					else{
						wait(NULL);
					}
					sleep(3600);
				}
			}
			else{
				if(min == tm->tm_min && hour== tm->tm_hour){
					pid_t pid;
					pid = fork();
			
					if(pid==0){
						execl("/bin/sh", "/bin/sh", "-c", argv[2], (char*) NULL);
						exit(0);
					}
				
					else{
						wait(NULL);
					}
					sleep(3600*24);
				}
			}
		}
	}

	return 0;
}
