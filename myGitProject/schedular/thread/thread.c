#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Header file for sleep()
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp) {
    
	for(int i=0; i<4; i++) {
		sleep(1);
		printf("Printing GeeksQuiz from Thread\n");
	}
	return NULL;
}

int main() {
	pthread_t thread_id;
	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	printf("has to come\n");
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit(0);
}

