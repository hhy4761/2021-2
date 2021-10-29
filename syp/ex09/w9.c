#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
struct msg  
{

	long msgtype;
	char data[100];
};

struct msg_ack
{
		long msgtype;
		char data[100];
};

int main()
{
	struct msg m1,m2;
	struct msg_ack ma1,ma2;

	int uid,receiver_id;
	printf("my id is\n");
	scanf("%d",&uid);
	printf("who to send?\n");
	scanf("%d",&receiver_id);

	key_t k = ftok(".",'a');
	key_t k2 = ftok(".",'b');
	int qid=msgget(k,IPC_CREAT|0644);
	int qid2=msgget(k2,IPC_CREAT|0644);

	if(fork())	
	{
		while(1)
		{
			m1.msgtype=uid;
			scanf(" %[^\n]s",m1.data);
			msgsnd(qid,&m1,strlen(m1.data)+1,0); 
		
		}
	}
	else
	{

		while(1)
		{
			if(msgrcv(qid,&m2,sizeof(m2),receiver_id,0)>0){
				printf("RECEIVED %s\n\n",m2.data);
				ma1.msgtype = uid;
				time_t s = time(NULL);
				struct tm *n = localtime(&s);
				char week[7][4] = {"Sun","Mon","Tue","Wed","Thr","Fri","Sat"};
				char mon[12][4] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
				sprintf(ma1.data,"%d read message at:	%s %s %d %d:%d:%d %d\n",uid,week[n->tm_wday],mon[n->tm_mon],n->tm_mday,n->tm_hour,n->tm_min,n->tm_sec,n->tm_year + 1900);
				msgsnd(qid2,&ma1,strlen(ma1.data)+1,0);
			}
			msgrcv(qid2,&ma2,sizeof(ma2),receiver_id,0);
				printf("%s\n",ma2.data);
			
		}
	}
}
