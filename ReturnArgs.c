#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *myThreadFunc(void *var)
{

    int *ptr = (int *)var;

    // sleep(3);

    for (int i = 0; i < 10; i++)
    {
        printf("My turn %d and *ptr is %d\n", i, *ptr);
        (*ptr)++;
    }
    return NULL;
}

void yourTurn()
{
    for (int i = 0; i < 10; i++)
    {
        printf("Your turn %d\n", i);
    }
}

int main()
{

    pthread_t threadID;

    int num = 10;

    pthread_create(&threadID, NULL, myThreadFunc, &num);
    yourTurn();

    pthread_join(threadID, NULL);

    printf("Thread is done and value of num is %d", num);

    return 0;
}