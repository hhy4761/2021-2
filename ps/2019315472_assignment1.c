#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#pragma warning(disable : 4996) // for VS users
typedef struct ele{
    bool is_num;
    bool is_str;

    double _num;
    char _str[21];
}ele;

int num_rows, num_cols;
int main()
{
	char cmd_type[50];
	bool Isnew = false;
	int i,j; //for loop
    int row,col; //sets, setn
    int r1,r2,c1,c2,count; //setrs,setrn
    double num; //setn,setrn
    char str[21]; // sets,setrs
    double sum; //sum

	ele** arr = (ele**)malloc(sizeof(ele*)*1); //for init arr
	
	while (1)
	{
		scanf("%s", cmd_type);

		if (!strcmp(cmd_type, "new"))
		{
			if(Isnew)
			{
				getchar();
				printf("TABLE EXISTS\n");
			}
			else
			{
				scanf("%d %d", &num_rows, &num_cols);
				arr = (ele**)realloc(arr,sizeof(ele*)*num_cols);
				for(i=0;i<num_rows;i++)
					arr[i] = (ele*)malloc(sizeof(ele)*num_rows);
                for(i=0;i<num_rows;i++){
                    for(j=0;j<num_cols;j++){
                        arr[i][j].is_num = false;
                        arr[i][j].is_str = false;
                    }
                }
				Isnew = true;
			}
		}

		else if(!strcmp(cmd_type, "setn"))
		{
			if(!Isnew)
			{
				printf("NO TABLE\n");
				continue;
			}
			else
			{
                scanf("%d %d %lf", &row,&col,&num);
                if(num_rows<=row || num_cols<=col){
                    printf("INDEX OUT-OF-RANGE\n");
                    continue;
                }
				arr[row][col]._num = num;
                arr[row][col].is_num = true;
                arr[row][col].is_str = false;
			}
		}
        else if(!strcmp(cmd_type, "sets"))
		{
			if(!Isnew)
			{
				printf("NO TABLE\n");
				continue;
			}
			else
			{
                char str[21];
                scanf("%d %d %s", &row,&col,str);
                if(num_rows<=row || num_cols<=col){
                    printf("INDEX OUT-OF-RANGE\n");
                    continue;
                }
				strcpy(arr[row][col]._str,str);
                arr[row][col].is_str = true;
                arr[row][col].is_num = false;
			}
		}
        else if(!strcmp(cmd_type, "setrn"))
		{
			if(!Isnew)
			{
				printf("NO TABLE\n");
				continue;
			}
			else
			{
                scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
                count = (r2-r1+1)*(c2-c1+1);
                double numbers[count];
                for(i=0;i<count;i++){
                    scanf("%lf",&numbers[i]);
                }
                if(r1>r2 || c1>c2){
                    printf("INDEX INVALID\n");
                    continue;
                }
                else if(num_rows<=r1||num_rows<=r2||num_cols<=c1||num_cols<=c2){
                    printf("INDEX OUT-OF-RANGE\n");
                    continue;
                }
                int cnt = 0;
                for(i=r1;i<=r2;i++){
                    for(j=c1;j<=c2;j++){
                        arr[i][j]._num = numbers[cnt];
                        arr[i][j].is_num = true;
                        arr[i][j].is_str = false;
                        cnt++;
                    }
                }
			}
		}
        else if(!strcmp(cmd_type, "setrs"))
		{
			if(!Isnew)
			{
				printf("NO TABLE\n");
				continue;
			}
			else
			{
                scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
                count = (r2-r1+1) * (c2-c1+1);
                char strs[count][20];
                for(i=0; i<count; i++){
                    scanf("%s",strs[i]);
                }
                if(r1>r2 || c1>c2){
                    printf("INDEX INVALID\n");
                    continue;
                }
                else if(num_rows<=r1||num_rows<=r2||num_cols<=c1||num_cols<=c2){
                    printf("INDEX OUT-OF-RANGE\n");
                    continue;
                }
                int cnt =0;
                for(i=r1;i<=r2;i++){
                    for(j=c1;j<=c2;j++){
                        strcpy(arr[i][j]._str,strs[cnt]);
                        arr[i][j].is_str = true;
                        arr[i][j].is_num = false;
                        cnt++;
                    }
                }
                
			}
		}
        else if(!strcmp(cmd_type, "sum"))
		{
			if(!Isnew)
			{
				printf("NO TABLE\n");
				continue;
			}
			else
			{
                scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
                if(r1>r2 || c1>c2){
                    printf("INDEX INVALID\n");
                    continue;
                }
                else if(num_rows<=r1||num_rows<=r2||num_cols<=c1||num_cols<=c2){
                    printf("INDEX OUT-OF-RANGE\n");
                    continue;
                }
                sum=0;
                for(i=r1;i<=r2;i++){
                    for(j=c1;j<=c2;j++){
                        if(arr[i][j].is_num){
                            sum += arr[i][j]._num;
                        }
                    }
                }
                printf("%.3f\n",sum);
                
			}
		}
        else if(!strcmp(cmd_type, "mean"))
		{
			if(!Isnew)
			{
				printf("NO TABLE\n");
				continue;
			}
			else
			{
                scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
                if(r1>r2 || c1>c2){
                    printf("INDEX INVALID\n");
                    continue;
                }
                else if(num_rows<=r1||num_rows<=r2||num_cols<=c1||num_cols<=c2){
                    printf("INDEX OUT-OF-RANGE\n");
                    continue;
                }
                sum=0;
                int cnt = 0;
                for(i=r1;i<=r2;i++){
                    for(j=c1;j<=c2;j++){
                        if(arr[i][j].is_num){
                            sum += arr[i][j]._num;
                            cnt++;
                        }
                    }
                }
                printf("%.3f\n",sum/cnt);
                
			}
		}
        else if(!strcmp(cmd_type, "search"))
		{
			if(!Isnew)
			{
				printf("NO TABLE\n");
				continue;
			}
			else
			{
                scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
                
                if(num_rows<=r1||num_rows<=r2||num_cols<=c1||num_cols<=c2){
                    printf("INDEX OUT-OF-RANGE\n");
                    continue;
                }
								else if(r1>r2 || c1>c2){
                    printf("INDEX INVALID\n");
                    continue;
                }
                scanf("%s",str);
                for(i=r1;i<=r2;i++){
                    for(j=c1;j<=c2;j++){
                        if(arr[i][j].is_str){
                            if(strstr(arr[i][j]._str,str) != NULL){
                                
                                printf("[%d,%d]\n",i,j);
                            }
                        }
                    }
                }
                
			}
		}
        else if (!strcmp(cmd_type, "print"))
		{
            if(!Isnew)
			{
				printf("NO TABLE\n");
				continue;
			}
			scanf("%d %d",&row,&col);
            if(num_rows<=row || num_cols<=col){
                printf("INDEX OUT-OF-RANGE\n");
                continue;
            }
            if(arr[row][col].is_num){
                printf("%10.3f\n",arr[row][col]._num);
            }
            else if(arr[row][col].is_str){
                printf("%10s\n",arr[row][col]._str);
            }
            else{
                printf("          \n");
            }
		}
        else if (!strcmp(cmd_type, "printr"))
		{
            if(!Isnew)
			{
				printf("NO TABLE\n");
				continue;
			}
			scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            count = (r2-r1+1)*(c2-c1+1);
            if(num_rows<=r1 || num_rows<=r2 || num_cols<=c1 || num_cols<=c2){
                printf("INDEX OUT-OF-RANGE\n");
                continue;
            }
					  else if(r1>r2 || c1>c2){
                printf("INDEX INVALID\n");
                continue;
            }
            for(i=r1; i<=r2; i++){
                for(j=c1; j<=c2; j++){
                    if(arr[i][j].is_num){
                        printf("%10.3f",arr[i][j]._num);
                    }
                    else if(arr[i][j].is_str){
                        printf("%10s",arr[i][j]._str);
                    }
                    else{
                        printf("          ");
                    }
                }
                printf("\n");
            }
		}
		else if (!strcmp(cmd_type, "exit"))
		{
			break;
		}
	}
	return 0;
}