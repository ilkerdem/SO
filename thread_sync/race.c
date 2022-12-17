#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdatomic.h>

const int NUM_THREADS = 1000, NUM_ITERS = 1000;

int global = 0;
//atomic_int global = 0;

void* main_thread(void *arg) {
	int i;
	for (i = 0; i < NUM_ITERS; ++i) 
		global++;
//		atomic_fetch_add(&global, 1);
	return NULL;
}

int main(void) {
	int i;
	pthread_t threads[NUM_THREADS];
	for (i = 0; i < NUM_THREADS; ++i)
		pthread_create(&threads[i], NULL, main_thread, NULL);
	for (i = 0; i < NUM_THREADS; ++i)
		pthread_join(threads[i], NULL); 
	printf("Total=%d\n",global);
}