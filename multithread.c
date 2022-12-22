#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>



volatile long int a = 0;
pthread_mutex_t aLock;



void threadFunc()
{
    int i;


    for (i = 1; i < 200000 ; i++)
    {
        a = a + 1;
    }
}



void threadFunc2()
{
    int i;


    for(i = 200000; i <= 500000; i++)
    {
        a = a + i;
    }
}



int main()
{
    pthread_t th_one, th_two; 
    int i;
    a = 0;


    pthread_create(&th_one, NULL, (void*)&threadFunc, NULL);  // Create a new thread for threadFunc
    pthread_create(&th_two, NULL, (void*)&threadFunc2, NULL); // Create a new thread for threadFunc2


    pthread_join(th_one, NULL);  // waiting to join thread "th_one" without status
    pthread_join(th_two, NULL);  // waiting to join thread "th_two" without status


    printf("%ld\n",a);

    return 0;
}
