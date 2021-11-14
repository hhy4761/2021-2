#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void my_signal_handler(int sig){
	for(int i=0;i<5;i++){
	printf("BEEP\n");
	sleep(1);
	}
	printf("I'm Alive\n");	
	
}
int main(){
	signal(SIGINT,my_signal_handler);
	while(1){
	}
	return 0;
}
