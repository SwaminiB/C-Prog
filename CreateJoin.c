#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* myTurn(void *arg)
{
    sleep(3);
    for(int i =0 ;i<10;i++)
    {
        printf("My turn %d\n",i);
    }

    return NULL;
}

void yourTurn()
{
    sleep(3);
    for(int i =0 ;i<10;i++)
    {
        printf("Your turn %d\n",i);
    }
}

int main()
{

    pthread_t threadID;
    pthread_create(&threadID, NULL, myTurn, NULL);
    yourTurn();
    pthread_join(threadID,NULL);

    return 0;
}