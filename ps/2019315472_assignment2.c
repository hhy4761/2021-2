#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned int **arr1;
    unsigned int **arr2;
    unsigned int input;
    scanf("%d",&input);
    arr1 = (unsigned int**)malloc((sizeof(unsigned int*))*input);
    arr2 = (unsigned int**)malloc((sizeof(unsigned int*))*input);

    for (int i=0; i<input; i++){
        arr1[i] = (unsigned int*)malloc((sizeof(unsigned int))*input);
    }
    for (int i=0; i<input; i++){
        arr2[i] = (unsigned int*)malloc((sizeof(unsigned int))*input);
    }
    for(int i=0;i<input;i++){
        for(int j=0; j<input;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    for(int i=0;i<input;i++){
        for(int j=0; j<input;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    
    int n = 0;
    int m = -1;
    int max = 0;
    int check =0;
    int row;
    int col;
    int size;
    // printf("start\n");
    for(int i=0; i<input; i++){
        for(int j=0; j<input;j++){
            if(arr1[i][j]==arr2[0][0]){
                // printf("36line %d %d\n",i,j);
                size=0;
                check = 0;
                n=0;
                m=-1;
                for(int ii=i; ii<input; ii++){
                    for(int jj=j; jj<input; jj++){
                        m++;
                        if(arr1[ii][jj]==arr2[n][m]){
                            size++;
                            if(ii==input-1 && jj==input-1){
                                if(size > max){
                                    max = size;
                                    row = i;
                                    col = j;
                                }
                                // printf("%d\n",max);
                            }
                        }
                        else{
                            check=1;
                            break;
                        }
                    }
                    n++;
                    m=-1;
                    if(check==1)
                        break;
                }
            }
        }
    }
    printf("%d %d 0 0",row,col);
}