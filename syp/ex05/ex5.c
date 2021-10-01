#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

		pid = fork();

		if(pid==0){
			execv(path,arg);
			exit(0);
		}
		else{
			wait(NULL);
		}
	}

}
