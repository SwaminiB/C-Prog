#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *myThreadFunc(void *var)
{

    char *message = (char *)malloc(sizeof(char) * 50);

    message = (char *)var;

    // sleep(3);
    printf("The message is %s\n", (message));

    return message;
}

int main()
{

    char *word = "Hello! World";
    char *txt;

    pthread_t threadID;
    pthread_create(&threadID, NULL, myThreadFunc, (void *)word);

    pthread_join(threadID, (void *)&txt);

    printf("Returned value is %s\n", txt);

    return 0;
}
