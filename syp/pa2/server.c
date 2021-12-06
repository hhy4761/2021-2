#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdbool.h>
#define MAXLINE 80

typedef struct _query {
    int user;
    int action;
    int seat;
} query;

typedef struct _user{
    int uid;
    int pwd;
    int seatnumber;
} User;
typedef struct _reserve{
    bool isReserved;
    int uid;
} reserve;

User user[1024]; //0~1023
bool islogged[1024];
reserve reserveInfo[256];

pthread_mutex_t lock;

void *thread_func(void *arg)
{
    query q;
    int n;
    
    int connfd = *((int *)arg);
    while ((n = read(connfd, &q, sizeof(query))) > 0){
        pthread_mutex_lock(&lock);
        int userid = q.user;
        int retval;
        if(!(q.user||q.seat||q.action)){ // termination
            int arr[256];
            for(int i=0; i<256; i++){
                arr[i] = reserveInfo[i].uid;
            }
            write(connfd, &arr, sizeof(arr));
            continue;
        }
        else if(user[userid].uid != -1){ // user등록되어 있을 때
        
            if(islogged[userid]){ // 로그인 되어있을 때
                if(q.action==1){ // 로그인 > fail   
                    retval = -1;
                }
                else if(q.action==2){// 예약
                    if(reserveInfo[q.seat].isReserved){ // 자리가 이미 예약 되었을 때 > fail
                        retval = -1;
                    }
                    else if(q.seat > 255){// seat number가 범위를 넘어섬 > fail
                        retval = -1;
                    }
                    else if(user[userid].seatnumber != -1){ // 이미 유저가 다른 자리를 예약을 한 경우
                            retval = -1;
                    }
                    else{
                        reserveInfo[q.seat].isReserved = true;
                        reserveInfo[q.seat].uid = userid;
                        user[userid].seatnumber = q.seat;
                        retval = user[userid].seatnumber;
                    }
                }
                else if(q.action==3){// 예약확인
                    if(user[userid].seatnumber == q.seat){ // 유저가 예약 되어있을때
                        retval = user[userid].seatnumber;
                    }
                    else{ // 예약 x 일 때 > fail
                        retval = -1;
                    }
                }
                else if(q.action==4){// 예약취소
                    if(user[userid].seatnumber != -1){// 해당 유저가 예약 되어있을 때
                        reserveInfo[q.seat].isReserved = false;
                        reserveInfo[q.seat].uid = -1;
                        retval = user[userid].seatnumber;
                        user[userid].seatnumber = -1;
                    }
                    else{ //예약 x 일 때 > fail
                        retval = -1;
                    }
                }
                else if(q.action==5){//로그아웃
                    if(islogged[userid]){// 로그인 되어있을 때
                        islogged[userid] = false;
                        retval = 1;
                    }
                }
            }
            else { // user 등록 but 로그인 되어 있지 않을 때
                if(q.action==1){ // 로그인
                    if(user[userid].uid == q.user && user[userid].pwd == q.seat){ // user, pwd 일치
                        islogged[userid] = true;
                        retval = 1;
                    }
                    else{// 로그인 시도 but 실패
                        retval = -1;
                    }
                }
                else if(q.action==2){// 예약 > fail
                    retval = -1;
                }
                else if(q.action==3){// 예약확인 > fail
                    retval = -1;
                }
                else if(q.action==4){// 예약취소 > fail
                    retval = -1;
                }
                else if(q.action==5){//로그아웃 > fail
                    retval = -1;
                }
            }
        }
        else{ //user 미등록되어 있을 때
            if(q.action==1){ // 회원가입
                user[userid].uid = userid;
                user[userid].pwd = q.seat;
                islogged[userid] = true;
                retval = 1;
            }
            else if(q.action==2){// 예약 > fail
                    retval = -1;
            }
            else if(q.action==3){// 예약확인 > fail
                retval = -1;
            }
            else if(q.action==4){// 예약취소 > fail
                retval = -1;
            }
            else if(q.action==5){//로그아웃 > fail
                retval = -1;
            }
        }
        pthread_mutex_unlock(&lock);
        write(connfd, &retval, sizeof(retval));
    }
    pthread_detach(pthread_self());
    free(arg);
    close(connfd);
    return NULL;
}
int main(int argc, char *argv[])
{
    int n, listenfd, connfd, caddrlen;
    struct hostent *h;
    struct sockaddr_in saddr, caddr;
    int port = atoi(argv[2]);

    for(int i=0; i<1024;i++){
        user[i].uid = -1;
        user[i].seatnumber = -1;
    }
    for(int i=0; i<1024;i++){
        islogged[i] = false;
    }
    for(int i=0; i<256;i++){
        reserveInfo[i].isReserved = false;
    }

    pthread_mutex_init(&lock,NULL);

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("socket() failed.\n");
        exit(1);
    }
    memset((char *)&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(port);
    if (bind(listenfd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
    {
        printf("bind() failed.\n");
        exit(2);
    }
    if (listen(listenfd, 5) < 0)
    {
        printf("listen() failed.\n");
        exit(3);
    }
    int *connfdp;
    pthread_t tid;
    while (1)
    {
        connfdp = (int*)malloc(sizeof(int));
        caddrlen = sizeof(caddr);
        if ((*connfdp = accept(listenfd, (struct sockaddr *)&caddr, (socklen_t *)&caddrlen)) < 0)
        {
            printf("accept() failed.\n");
            continue;
        }
        pthread_create(&tid,NULL,thread_func,connfdp);
    }
}