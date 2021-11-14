#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <grp.h>
#include <pwd.h>

int ls(char *dir_path, char *option);
int head(char *file_path, char *line);
int tail(char *file_path, char *line);
int mv(char *file_path1, char *file_path2);
int cp(char *file_path1, char *file_path2);
int pwd();

int main(){
	while(1){
		int i, cmdrlt;
		char *cmd;
		char *argument[10];
	        size_t size;	
		
		getline(&cmd, &size, stdin);
		cmd[strlen(cmd) - 1] = '\0';

		if (strlen(cmd) == 0){
			printf("ERROR: invalid command\n");
			continue;
		}
		i = 0;
		char *ptr = strtok(cmd, " ");

		while(ptr != NULL){
			argument[i++] = ptr;
			ptr = strtok(NULL, " ");
		}
		argument[i++] = NULL;
		argument[i++] = NULL;
		argument[i] = NULL;

		if (strcmp("ls", argument[0]) == 0){
			cmdrlt = ls(argument[1], argument[2]);		
		}
		else if (strcmp("head", argument[0]) == 0){
			cmdrlt = head(argument[3], argument[2]);
		}
		else if (strcmp("tail", argument[0]) == 0){
			cmdrlt = tail(argument[3], argument[2]);
		}
		else if (strcmp("mv", argument[0]) == 0){
			cmdrlt = mv(argument[1], argument[2]);
		}
		else if (strcmp("cp", argument[0]) == 0){
			cmdrlt = cp(argument[1], argument[2]);
		}
		else if (strcmp("pwd", argument[0]) == 0){
			cmdrlt = pwd();
		}
		else if (strcmp("quit", argument[0]) == 0){
			break;
		}
		else{
			printf("ERROR: invalid command\n");
		}

		if (cmdrlt == -1){
			printf("ERROR: The command is executed abnormally\n");
		}
		printf("\n");
	}
	return 0;
}

int ls(char *dir_path, char *option){
	
       	int count = 0;
       	struct dirent** files = NULL; 
	char *cur_dir = getcwd(NULL,200);	
	if(dir_path==NULL)
		dir_path = ".";
	if(strcmp(dir_path,"-al")==0){
		option = "-al";
		dir_path = ".";
	}
	count = scandir(dir_path, &files, NULL, alphasort); 
	
	if(count == -1){
		printf("ERROR: invalid path\n");
		return -1;
	}

	for (int i = 0; i < count; i++) {
		if(option==NULL){
			if(strcmp(".",files[i]->d_name)==0)
				continue;
		
			else if(strcmp("..",files[i]->d_name)==0)
				continue;
			else if(files[i]->d_name[0] == '.')
				continue;
			printf("%s ",files[i]->d_name);
		}
		
		else if(strcmp(option,"-al")==0){
			chdir(dir_path);
			struct stat st;
			stat(files[i]->d_name,&st);
			char permission[11];
			struct passwd *pwd;
			struct group *grp;
			pwd = getpwuid(st.st_uid);
			grp = getgrgid(st.st_gid);
			int mode = st.st_mode;
			if( S_ISCHR(mode)) permission[0]='c';
			else if(S_ISDIR(mode)) permission[0]='d';
			else if( S_ISBLK(mode)) permission[0]='b';
			else if(S_ISSOCK(mode)) permission[0]='s';
			else if( S_ISLNK(mode))	permission[0]='l';
			else permission[0]='-';
			if( S_IRUSR & mode) permission[1]='r';
			else permission[1]='-';
			if(S_IWUSR & mode) permission[2]='w';
			else permission[2]='-';
			if(S_IXUSR & mode) permission[3]='x';
			else permission[3]='-';
			if(S_IRGRP & mode) permission[4]='r';
			else permission[4]='-';
			if(S_IWGRP & mode) permission[5]='w';
			else permission[5]='-';
			if(S_IXGRP & mode) permission[6]='x';
			else permission[6]='-';
			if(S_IROTH & mode) permission[7]='r';
			else permission[7]='-';
			if(S_IWOTH & mode) permission[8]='w';
			else permission[8]='-';
			if(S_IXOTH & mode) permission[9]='x';
			else permission[9]='-';
			printf("%s ",permission);
			printf("%ld ",st.st_nlink);
			printf("%s ",pwd->pw_name);
			printf("%s ",grp->gr_name);
			printf("%ld ",st.st_size);
			printf("%s\n",files[i]->d_name);
			
		}
		chdir(cur_dir);
		free(files[i]);	
		files[i]=NULL;
		
	}  
	free(files);
	files=NULL;
	
	return 0;	

}

int head(char *file_path, char *line){
	int rdfd,len,count;
	int cur_no = 0;	
	char buf[4096];
	if((file_path==NULL) || (line==NULL))
		return -1;
	count = atoi(line);
	if((rdfd = open(file_path,O_RDONLY))==-1){
		printf("ERROR: invalid path\n");
		return -1;
	}
	while((len=read(rdfd,buf,4096))>0){
		for(int i=0;i<4096;i++){
			if(buf[i] == '\n')
				cur_no++;
			if(buf[i] == '\0')
				cur_no++;
			printf("%c",buf[i]);
			if(cur_no >= count)
				break;
		}
		if(cur_no >= count)
			break;
	}
	close(rdfd);
	return 0;	
}

int tail(char *file_path, char *line){
	int fd1,fd2,len;
	int count = 0;	
	int cur_no =0;
	int cnt = 0;
 	char fd1_buf[4097];
	char fd2_buf[4097];
	if((file_path==NULL) || (line==NULL))
		return -1;
	count = atoi(line);
	if((fd1 = open(file_path,O_RDONLY))==-1){
		printf("ERROR: invalid path\n");
		return -1;
	}
	lseek(fd1,-1,SEEK_END);
	for(;;){
		read(fd1,fd1_buf,1);
		lseek(fd1,-2,SEEK_CUR);
		if(strcmp(fd1_buf,"\n")==0){
			cnt++;
		}
		if(cnt==count+1)
			break;
	}
	lseek(fd1,2,SEEK_CUR);
	while(read(fd1,fd1_buf,1)>0){
		printf("%s",fd1_buf);
	}
	close(fd1);
	return 0; 
}

int mv(char *file_path1, char *file_path2){
	if(link(file_path1, file_path2)==-1){
		printf("ERROR: invalid path\n");
		return -1;
	}
	unlink(file_path1);

	close(*file_path1);
	return 0;	

}

int cp(char *file_path1, char *file_path2){
	int rdfd,wrfd,len;
	char buf[4097];
	if((rdfd = open(file_path1,O_RDONLY))==-1){
		printf("ERROR: invalid path\n");
		return -1;
	}
	if((wrfd = open(file_path2,O_CREAT | O_WRONLY | O_TRUNC))==-1){
		printf("ERROR: invalid path\n");
		return -1;
	}
	while((len = read(rdfd,buf,4096))>0){
		write(wrfd,buf,len);
	}
	close(rdfd);
	close(wrfd);
	return 0;
}

int pwd(){
	char* cwd;
	cwd = getcwd(NULL,200);
	if(cwd == NULL)
		return -1;
	else{
		printf("%s",cwd);
		return 0;
	}	
}
