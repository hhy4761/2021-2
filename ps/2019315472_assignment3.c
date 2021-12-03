#include <stdio.h>

int map[20][10] = {0}; 

int lineCheck(){
    
    int cnt;
    int row;
    int s =0;
    for(int i=19; i>=0; i--){
        cnt = 0;
        for(int j=0;j<10;j++){
            if(map[i][j]==1)
                cnt++;
            else
                break;
        }
        if(cnt == 10){
            row = i;
            s = 1;
            break;
        }
    }
    
    if(s){
        for(int k=row; k>=0; k--){
            for(int l=0; l<10; l++){
                if(k==0){
                    map[k][l] = 0;
                }
                else
                    map[k][l] = map[k-1][l];
                }
            }
    }
    if(s==1)
        return 1;
    else
        return 0;
    
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        int type,col;
        scanf("%d %d",&type,&col);
        if(type==1){
            for(int n=3; n<20; n++){
                if(map[n][col]==1 || map[n][col+1]==1){
                    map[n-1][col] = 1;
                    map[n-1][col+1] = 1;
                    map[n-2][col] = 1;
                    map[n-3][col] = 1;
                    break;
                }
                else if(n==19){
                    map[n][col] = 1;
                    map[n][col+1] = 1;
                    map[n-1][col] = 1;
                    map[n-2][col] = 1;
                    break;
                }
            }
        }
        else if(type==2){
            for(int n=3; n<20; n++){
                if(map[n][col]==1){
                    map[n-1][col] = 1;
                    map[n-2][col] = 1;
                    map[n-3][col] = 1;
                    break;
                }
                else if(n==19){
                    map[n][col] = 1;
                    map[n-1][col] = 1;
                    map[n-2][col] = 1;
                    break;
                }
            }
        }
        else if(type==3){
            for(int n=1; n<20; n++){
                if(map[n][col]==1 && map[n][col+1]==0 && map[n][col+2]==0){
                    map[n-1][col]=1;
                    map[n-1][col+1]=1;
                    map[n][col+1]=1;
                    map[n][col+2]=1;
                    break;
                }
                else if( n>1 && (map[n][col+1]==1 || map[n][col+2]==1)){
                    map[n-1][col+1] = 1;
                    map[n-1][col+2] = 1;
                    map[n-2][col] = 1;
                    map[n-2][col+1] = 1;
                    break;
                }
                else if(n==19){
                    map[n][col+1] = 1;
                    map[n][col+2] = 1;
                    map[n-1][col] = 1;
                    map[n-1][col+1] = 1;
                    break;
                }
            }
        }
        else if(type==4){
            for(int n=1; n<20; n++){
                if(map[n][col]==1 || map[n][col+1]==1 || map[n][col+2]==1){
                    map[n-1][col] = 1;
                    map[n-1][col+1] = 1;
                    map[n-1][col+2] = 1;
                    break;
                }
                else if(n==19){
                    map[n][col] = 1;
                    map[n][col+1] = 1;
                    map[n][col+2] = 1;
                    break;
                }
            }
        }
        else if(type==5){
            for(int n=2; n<20; n++){
                if(map[n][col]==1 || map[n][col+1]==1){
                    map[n-1][col] = 1;
                    map[n-1][col+1] = 1;
                    map[n-2][col] = 1;
                    map[n-2][col+1] = 1;
                    break;
                }
                else if(n==19){
                    map[n][col] = 1;
                    map[n][col+1] = 1;
                    map[n-1][col] = 1;
                    map[n-1][col+1] = 1;
                    break;
                }
            }
        }
        else if(type==6){
            for(int n=2; n<20; n++){
                if(map[n][col]==1 || map[n][col+1]==1 || map[n][col+2]==1){
                    map[n-1][col] = 1;
                    map[n-1][col+1] = 1;
                    map[n-1][col+2] = 1;
                    map[n-2][col+1] = 1;
                    break;
                }
                else if(n==19){
                    map[n][col] = 1;
                    map[n][col+1] = 1;
                    map[n][col+2] = 1;
                    map[n-1][col+1] = 1;
                    break;
                }
            }
        }
        else if(type==7){ 
            for(int n=2; n<20; n++){
                if(map[n][col]==0 && map[n][col+1]==1 && map[n][col+2]==0){
                    map[n][col] = 1;
                    map[n][col+2] = 1;
                    map[n-1][col+1] = 1;
                    map[n-2][col] = 1;
                    map[n-2][col+2] = 1;
                    break;
                }
                else if( n>2 && (map[n][col]==1 || map[n][col+2]==1)){
                    map[n-1][col] = 1;
                    map[n-1][col+2] = 1;
                    map[n-2][col+1] = 1;
                    map[n-3][col] = 1;
                    map[n-3][col+2] = 1;
                    break;
                }
                else if(n==19){
                    map[n][col] = 1;
                    map[n][col+2] = 1;
                    map[n-1][col+1] = 1;
                    map[n-2][col] = 1;
                    map[n-2][col+2] = 1;
                    break;
                }
            }
        }
        else if(type==8){
            for(int n=2; n<20; n++){
                if((map[n][col]==1 && map[n][col+1]==0) || (map[n][col+2]==1 && map[n][col+1]==0)){
                    map[n][col+1] = 1;
                    map[n-1][col] = 1;
                    map[n-1][col+1] = 1;
                    map[n-1][col+2] = 1;
                    map[n-2][col+1] = 1;
                    break;
                }
                else if( n>2 && map[n][col+1]==1){
                    map[n-1][col+1] = 1;
                    map[n-2][col] = 1;
                    map[n-2][col+1] = 1;
                    map[n-2][col+2] = 1;
                    map[n-3][col+1] = 1;
                    break;
                }
                else if(n==19){
                    map[n][col+1] = 1;
                    map[n-1][col] = 1;
                    map[n-1][col+1] = 1;
                    map[n-1][col+2] = 1;
                    map[n-2][col+1] = 1;
                    break;
                }
            }
        }
    lineCheck();
    }
    for(int i=0;i<20;i++){
        for(int j=0; j<10; j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}