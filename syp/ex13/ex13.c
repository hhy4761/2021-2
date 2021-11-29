#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <time.h>
#define random() ((double)rand() / (RAND_MAX + 1))

double global_inside_points = 0;
double global_total_points = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* func(void* n){
	srand(time(NULL));
	int num = *(int*)n;
	double x=0;
	double y=0;
	double r=0;
	for(int i=0; i<num; i++){
		x = random();
		y = random();
		r = sqrt(x*x+y*y);
		pthread_mutex_lock(&m);
		if(r<=1)
			global_inside_points++;
		global_total_points++;
		pthread_mutex_unlock(&m);
	}
	return;
}

int main(int argc, char** argv)
{
	int numofthreads = atoi(argv[1]);
	int numofpoints = atoi(argv[2]);
	pthread_t t[numofthreads];

	for(int i=0;i<numofthreads;i++){
		pthread_create(&t[i],NULL,func,&numofpoints);
	}
	for(int i=0;i<numofthreads;i++){
		pthread_join(t[i],NULL);
	}
	double pi = 4*(global_inside_points/global_total_points);
	printf("pi = %lf",pi);
}
