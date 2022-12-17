#define _GNU_SOURCE		
#include <unistd.h>
#include <sys/syscall.h>   
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

const int NUM_THREADS = 100, NUM_ITERS = 1000;

int global = 0;
pthread_mutex_t mutex;


void* main_thread(void *arg) {
	int i;
	for (i = 0; i < NUM_ITERS; ++i)
	{ 
//		pthread_mutex_lock(&mutex);
		global++;
//		pthread_mutex_unlock(&mutex);
	}
//	printf("Thread number %ld finished\n",syscall(SYS_gettid)-getpid());
	return NULL;
}

int main(void) {
	int i;
	pthread_mutex_init(&mutex, NULL);

	pthread_t threads[NUM_THREADS];
	for (i = 0; i < NUM_THREADS; ++i)
		pthread_create(&threads[i], NULL, main_thread, NULL);
	for (i = 0; i < NUM_THREADS; ++i)
		pthread_join(threads[i], NULL); 
	printf("Total=%d\n",global);
}