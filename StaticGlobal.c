#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int globalVar = 10;

void *myThreadFunc1(void *var)
{

    // sleep(5);
    globalVar += 5;

    printf("The value of globalVar is %d\n", globalVar);

    static int staticVar = 50;

    for (int i = staticVar; i < 55; i++)
    {
        staticVar++;
        printf("Static var: %d\n", staticVar);
    }

    return NULL;
}


void *myThreadFunc2(void *var)
{

    // sleep(5);
    // globalVar += 5;

    printf("The value of globalVar is %d\n", globalVar);

    // static int staticVar = 50;

    // for (int i = staticVar; i < 55; i++)
    // {
    //     staticVar++;
        // printf("Static var: %d\n", staticVar);
    // }

    return NULL;
}

int main()
{

    pthread_t threadID1 , threadID2;

    // for (int i = 0; i < 3; i++)
        pthread_create(&threadID1, NULL, myThreadFunc1, NULL);
        pthread_create(&threadID2, NULL, myThreadFunc2, NULL);

    // for (int i = 0; i < 3; i++)
        pthread_join(threadID1, NULL);
        pthread_join(threadID2, NULL);

    return 0;
}