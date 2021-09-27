#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char** argv)
{
	int fd1,fd2;
	char buf[16];

	if((fd1 = open(argv[1],O_RDWR))<0)
	{
		perror("open");
		exit(1);
	}
	
	if((fd2 = open("Aladdin_num.txt",O_RDWR|O_CREAT))<0)
	{
		perror("open");
		exit(1);
	}

	int n,i,j,k,l,a,b;
	int cnt = 1;
	char buff[5];
	buff[0] = (char)cnt+48;
	char bufff[5] = " |";
	write(fd2,buff,sizeof(buff));
	write(fd2,bufff,sizeof(bufff));	
	while((n = read(fd1, buf, 1)) > 0){
		if(buf[0]=='\n'){
			cnt++;
			buff[0] = (char)cnt+48;
			if(cnt>9 && cnt<100){
				i=cnt/10;
				j=cnt%10;
				buff[0] = (char)i+48;
				buff[1] = (char)j+48;
			}
			else if(cnt>99 && cnt < 1000){
				a=cnt/10;
				i = a/10;
				j = a%10;
				k = cnt%10;
				buff[0] = (char)i+48;
				buff[1] = (char)j+48;
				buff[2] = (char)k+48;
			}
			else if(cnt>999 && cnt < 10000){
				b = cnt/10;
				a = b/10;
				i = a/10;
				j = a%10;
				k = b%10;
				l = cnt%10;
				buff[0] = (char)i+48;
				buff[1] = (char)j+48;
				buff[2] = (char)k+48;
				buff[3] = (char)l+48;
			}

			write(fd2,buf,n);
			write(fd2,buff,sizeof(buff));
			write(fd2,bufff,sizeof(bufff));
		}
		else
			write(fd2,buf,n);

	}
	return 0;
}
