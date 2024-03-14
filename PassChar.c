#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *myThreadFunc(void *var)
{

    char *message;
    message = (char *)var;

    printf("The thread says %s\n", message);

    return NULL;
}

int main()
{

    char *word1 = "Hello";
    char *word2 = "Good Evening";

    int returnValueOfThread1,returnValueOfThread2;

    pthread_t threadID1;
    returnValueOfThread1 = pthread_create(&threadID1, NULL, myThreadFunc, (void *)word1);
    pthread_join(threadID1,NULL);

    pthread_t threadID2;
    returnValueOfThread2 = pthread_create(&threadID2, NULL , myThreadFunc, (void*)word2);
    pthread_join(threadID2,NULL);

    printf("The return value of thread1 is %d\n", returnValueOfThread1);
    printf("The return value of thread2 is %d\n", returnValueOfThread2);

    return 0;
}