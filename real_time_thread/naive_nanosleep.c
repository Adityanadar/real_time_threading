#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define BILLION 1E9

void *thread_function(void *ptr){
    int count = 0;
    struct timespec remaining, request = { 0, 100000 }, start, end;
  
    
    // measuring time using gettime
    clock_gettime(CLOCK_MONOTONIC, &start);
    while(count < 10000){
        // nanosleep inside function for 1 ms sleep
        //ts.tv_sec
        nanosleep(&request, &remaining);
        count++;

    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    // Calculate time it took
    double time_spent = ( end.tv_sec - start.tv_sec )
    + ( end.tv_nsec - start.tv_nsec )/BILLION;

    printf( "time spent is %f:", time_spent );
}

void main(){
    pthread_t thread1;
    int ret_thread;
    ret_thread = pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_join(thread1, NULL);
    exit(0);
}