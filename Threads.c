#include <pthread.h>
pthread_t threads[8];
// Protect critical areas from getting clobbered
pthread_mutex_t lock = PTHREAD_MUTEXT_INITIALIAZER;

void *myFunc(void *thread);

double calculatedPi = 1.0;

int main(){
    int i = 0
    /* Thread creation */
    for(i = 0; i < 8; i++){
        pthread_create(&threads[i], NULL, myFunc, (void *) i);
        pthread_join(&myThread, NULL);
    }
}

void *myFunc(void *thread){
    int threadNo = (int) thread;
    pthread_mutex_lock(&lock);
    // Loop 25,000 times
    // Every 10 times, update the global variable
    calculatedPi *= 0; // Wait.. We need to protect the global variable
}