#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
int main(){
		pid_t pid;
		char *cmd;
		size_t size;
		char *arg[10];
		while(1){
				getline(&cmd, &size, stdin);
				cmd[strlen(cmd)-1] = '\0';
				if(strcmp(cmd,"quit") ==0){
						return 0;
				}
				char *ptr = strtok(cmd," ");

				int i=0;
				while(ptr != NULL){
						arg[i++] = ptr;
						ptr = strtok(NULL," ");
				}
				arg[i] = NULL;
				char path[100];
				sprintf(path, "/bin/%s", arg[0]);
				int k;
				bool pi = false;
				for(k=0;arg[k]!=NULL;k++){
					if(strcmp(arg[k],"|")==0){
						pi = true;
						break;
					}
				}
				k++;
				char *arg2[10];
				for(int c=0;arg[k]!=NULL;c++){
						arg2[c] = arg[k];
						k++;
				}
				//pipe
				int p_fd[2];
				pipe(p_fd);
				pid = fork();
				if(pid==0){
						int i;
						int fd;
						bool inred = false;
						bool outred = false;
						//bool pi = false;
						for(i=0;arg[i]!=NULL;i++){
								if(strcmp(arg[i],">")==0){
										outred = true;
										break;
								}
								else if(strcmp(arg[i],"<")==0){
										inred=true;
										break;
								}
								else if(strcmp(arg[i],"|")==0){
										pi=true;
										break;
								}
						}
						if(outred){
							fd=open(arg[i+1],O_RDWR|O_CREAT);
							dup2(fd,1);
							close(fd);
							arg[i]=NULL;
						}
						else if(inred){
							fd=open(arg[i+1],O_RDONLY);
							dup2(fd,0);
							close(fd);
							arg[i]=NULL;
						}	
						else if(pi){
							dup2(p_fd[1],1);
							close(p_fd[0]);
							close(p_fd[1]);
							arg[i]=NULL;
						}
						execvp(arg[0],arg);
						exit(0);
				}
		else{
				pid_t pid2;
				pid2 = fork();
				if(pid2==0 && pi){
						dup2(p_fd[0],0);
						close(p_fd[1]);
						close(p_fd[0]);
						int i;
						for(i=0;arg2[i]!=NULL;i++){
						}
						arg2[i-1]=NULL;
						execvp(arg2[0],arg2);
						exit(0);
				}
				else{
					wait(NULL);
				}
		}

}
}

