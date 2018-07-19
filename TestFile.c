/*
// Most of the code format came from this YouTube video:
// https://www.youtube.com/watch?v=GXXE42bkqQk&t=1s

#include <stdio.h>
#include <pthread.h>

#define NUM_LOOPS 25000

double piSum = 1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Initialize the mutex functionality

*/
/*struct pi_function_struct {
    int start;
    double piSum;
};*//*


//Pi formula came from: https://github.com/aureleoules/Pi-WallisProduct/blob/master/main.cpp
void *pi_function(void* arg) {

//    struct pi_function_struct *arg_struct = (struct pi_function_struct*) arg;

    double p, pi = 2.0;
    for (int i = 2; i <= NUM_LOOPS; i += 2) { //25,000 is the precision of the Pi value
        pi = pi * ((p = i) / (i - 1));
        pi = pi * (p / (i + 1)); //Formula for WillisProduct
        pthread_mutex_lock(&mutex); // Locks the variable in the critical section so multiple threads access
                                    // them at the same time.

        piSum = pi; // Send the result of WillisProduct to the global variable.

        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL); // States that the work of the thread is complete.

}

int main(void) {

    //TODO: Make an overlapping for loop in pi_function that increases the starting value
    //TODO: Create variable that will increment in loop to be passed into pi_function

    int num_threads = 8; // The number of threads  to execute WillisProduct
    pthread_t tids[num_threads]; // The creation of the array of thread objects.
    for (int i = 0; i < num_threads; i++) { // Create 8 threads to execute the WillisProduct
        pthread_create(&tids[i], NULL, pi_function, NULL);
    }
    for (int i = 0; i < num_threads; i++) { // Wait for each thread to complete
        pthread_join(tids[i], NULL);
    }

    printf("All threads done, value calculated to %.14f\n", piSum); // Display result of WillisProduct
    double actual_pi = 3.14159265358979;
    double pi_diff = piSum - actual_pi;
//    printf("The actual value of Pi is 3.14159265358979\n"); // Debugging print statement
    printf("This is off by about %.14f\n", pi_diff); // Difference between actual Pi value and result of WillisProduct
    return 0;
}
*/
