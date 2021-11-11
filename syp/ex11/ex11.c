#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int** mat1;
int* mat2;
int len;

void* func(void* arg){
		int c = (int)arg;
		int res=0;
		for(int i=0;i<len;i++){
			res += mat1[c][i] * mat2[i];
		}
		return (void*)res;
}

int main(int argc, char** argv){
	srand(time(NULL));
	int row = atoi(argv[1]);
	int col = atoi(argv[2]);
	int **arr;
	int *vec;
	arr = (int**)malloc(sizeof(int*)*row);
	for(int i=0; i<row; i++){
			arr[i]=(int*)malloc(sizeof(int)*col);
	}
	vec = (int*)malloc(sizeof(int)*col);
	printf(" *** Matirx *** \n");
	for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
					arr[i][j] = rand() % 10;
					printf("[ %d ]",arr[i][j]);
			}
		printf("\n");
	}
	mat1 = arr;

	printf(" *** Vector ***\n");
	for(int i=0; i<col;i++){
		vec[i] = rand()%10;
		printf("[ %d ]",vec[i]);
		printf("\n");
	}
	mat2 = vec;
	len = col;

	printf(" *** Result ***\n");
	
	pthread_t tid[row];
	for(int i=0; i<row; i++){
		pthread_create(&tid[i],NULL,func,(void*)i);
	}
	
	for(int i=0; i<row; i++){
		int result;
		pthread_join(tid[i],(void*)&result);
		printf("[ %d ]\n",result);
	}
	return 0;
}

