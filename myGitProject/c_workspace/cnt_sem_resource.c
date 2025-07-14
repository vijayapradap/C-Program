#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_RESOURCES 3

sem_t counting_sem;

void* thread_function(void* arg) {
    sem_wait(&counting_sem); // Wait (P operation)
    printf("Thread %ld: Acquired a resource\n", (long)arg);
    sleep(1); // Simulate work
    printf("Thread %ld: Released a resource\n", (long)arg);
    sem_post(&counting_sem); // Signal (V operation)
    return NULL;
}

int main() {
    pthread_t threads[5];

    sem_init(&counting_sem, 0, NUM_RESOURCES); // Initialize to the number of resources

    for (long i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*)i);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&counting_sem); // Destroy semaphore

    return 0;
}