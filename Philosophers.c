#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <semaphore.h>

pthread_t philosophers[5];
pthread_mutex_t chopsticks[5];

void *myThreadFunc(int n)
{

    printf("Philosopher %d is thinking\n", n);

    pthread_mutex_lock(&chopsticks[n]);
    pthread_mutex_lock(&chopsticks[(n + 1) % 5]);

    printf("Philosopher %d is eating\n", n);

    int num = (rand() % 10 +1 );
    // printf("%d\n",num);

    sleep(num);

    pthread_mutex_unlock(&chopsticks[n]);
    pthread_mutex_unlock(&chopsticks[(n + 1) % 5]);

    printf("Philosopher %d finished eating\n", n);

    return NULL;
}

int main()
{
    int k;

    for (int i = 1; i <= 5; i++)
    {
        k = pthread_mutex_init(&chopsticks[i], NULL);

        if (k != 0)
        {
            printf("Failed to initialize the mutex\n");
        }
    }

    for (int i = 1; i <= 5; i++)
    {

        k = pthread_create(&philosophers[i], NULL,  myThreadFunc, (int *)i);

        if (k != 0)
        {
            printf("Failed to create thread\n");
        }
    }

    for (int i = 1; i <= 5; i++)
    {
        pthread_join(philosophers[i], NULL);

        if (k != 0)
        {
            printf("Failed to join thread\n");
        }
    }

    for (int i = 1; i <= 5; i++)
    {
        k = pthread_mutex_destroy(&chopsticks[i]);

        if (k != 0)
        {
            printf("Failed to destroy the mutex\n");
            return 0;
        }
    }
    return 0;
}