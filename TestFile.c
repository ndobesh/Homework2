// Most of the code format came from this YouTube video:
// https://www.youtube.com/watch?v=GXXE42bkqQk&t=1s

#include <stdio.h>
#include <pthread.h>

#define NUM_LOOPS 25000

double piSum = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//Pi formula came from: https://github.com/aureleoules/Pi-WallisProduct/blob/master/main.cpp
void* pi_function() {
    double p, pi = 2.0;
    for (int i = 2; i <= NUM_LOOPS; i += 2) { //25,000 is the precision of the Pi value
        pi = pi * ((p = i) / (i - 1));
                pi = pi * (p / (i + 1)); //Formula for WillisProduct
                pthread_mutex_lock(&mutex);

                piSum = pi;

                pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);

}

int main(void) {
    // pi_function();

    pthread_t tid;
    pthread_create(&tid, NULL, pi_function, NULL);
    pthread_join(tid, NULL);

    printf("All threads done, value calculated to %.14f\n", piSum);
    double actual_pi = 3.14159265358979;
    double pi_diff = piSum - actual_pi;
//    printf("The actual value of Pi is 3.14159265358979\n"); // Debugging print statement
    printf("This is off by about %.14f\n", pi_diff); // Will need to calc diff between calc and actual
    return 0;
}
