#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

sem_t sem;

void* thread_A(void *arg) {
	srand(pthread_self());
	sleep(rand()%3);
	printf("Point A has been reached now!\n"); //Point A
//	sem_post(&sem);
    return NULL;
}


void* thread_B(void *arg) {
	srand(pthread_self());
	sleep(rand()%3);
//	sem_wait(&sem);
	printf("Point B has been reached now!\n"); //Point B
    return NULL;
}

int main(void) {
    int i;
    pthread_t threads[2];
	//Initialize a semphapore to be shared by threads with initial value 0
	sem_init(&sem, 0,0);
        pthread_create(&threads[0], NULL, thread_A, NULL);
        pthread_create(&threads[1], NULL, thread_B, NULL);
    for (i = 0; i < 2; ++i)
        pthread_join(threads[i], NULL); 
}