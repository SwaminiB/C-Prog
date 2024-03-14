#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define BIG 1000000000
long int counter = 0;
pthread_mutex_t counterMutex = PTHREAD_MUTEX_INITIALIZER;

void *myThreadFunc(void *var)
{

    // sleep();

    for (long int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&counterMutex);
        counter++;
        pthread_mutex_unlock(&counterMutex);
    }

    return NULL;
}

int main()
{

    pthread_t threadID1,threadID2;
    pthread_create(&threadID1, NULL, myThreadFunc, NULL);
    pthread_create(&threadID2, NULL, myThreadFunc, NULL);

    pthread_join(threadID1, NULL);
    pthread_join(threadID2, NULL);

    printf("%d\n", counter);

    return 0;
}