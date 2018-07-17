#include <pthread.h>
#include <stdio.h>
pthread_t threads[8];
// Protect critical areas from getting clobbered
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *myFunc(void *thread);
double getPI();

double calculatedPi = 1.0; //Global variable to hold grand total for Pi

int main(){
    int i = 0;
    /* Thread creation */
    for(i = 0; i < 8; i++){
        pthread_create(&threads[i], NULL, myFunc, (void *) i);
        void *myFunc(void *thread);
        for(int i =0; i < 8; i++){
            pthread_join(&threads, NULL);
        }

    }
}

void *myFunc(void *thread){
    int threadNo = (int) thread;
    pthread_mutex_lock(&lock);
    // Loop 25,000 times
    // Every 10 times, update the global variable
    for (int i = 0; i < 8; i++) {
        pthread_join(threads[i], NULL);
    }
    calculatedPi *= 0; // Wait.. We need to protect the global variable
}

// Pi calculation formula
// Source: https://github.com/aureleoules/Pi-WallisProduct/blob/master/main.cpp

double getPI() {
    double p, pi = 2.0;
    for(int i = 2; i <= 25000; i += 2) {
        pi = pi * ((p=i)/(i-1))*(p/(i+1));
    }
    return pi;
}