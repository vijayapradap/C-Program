/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

pthread_mutex_t mutex;
volatile bool a = false;

void *pthread_1_handler(void *arg) {
    (void)arg;
    while(1) {
        pthread_mutex_lock(&mutex);
        if (a == false) {
            printf("I am inside thread 1\n");
            a = true;
        }
        pthread_mutex_unlock(&mutex);
        usleep(10000);
    }
}

void *pthread_2_handler(void *arg) {
    (void)arg;
    while(1) {
        pthread_mutex_lock(&mutex);
        if (a == true) {
            printf("I am inside thread 2\n");
            a = false;
        }
        pthread_mutex_unlock(&mutex);
        usleep(10000);
    }
}

int main()
{
    pthread_t tid_1, tid_2;
    
    pthread_mutex_init(&mutex, NULL);
    
    pthread_create(&tid_1, NULL, pthread_1_handler, NULL);
    pthread_create(&tid_2, NULL, pthread_2_handler, NULL);
    pthread_detach(tid_1);
    pthread_detach(tid_2);
    
    int x = 0;
    
    while(x++ < 2) {
        sleep(1);
    }
    
    pthread_mutex_destroy(&mutex);

    return 0;
}