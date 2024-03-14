#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

pthread_mutex_t mutex;
sem_t wrt;

int cnt;
int NumberOfReaders = 0;

void *writer(void *i)
{

    sem_wait(&wrt);

    // Critical Section starts
    // sleep(3);

    cnt = rand() % 100;
    printf("Writer %d has entered data %d\n", *(int *)i , cnt);

    if(cnt%4 == 0){
        ( printf("%d is divisible by 4\n",cnt));
    }
    else{
        (printf("%d is not divisible by 4\n",cnt));
    }
    //Critical section ends

    sem_post(&wrt);

    return NULL;
}

void *reader(void *i)
{

    pthread_mutex_lock(&mutex);
    NumberOfReaders++;

    if (NumberOfReaders == 1)
  
        sem_wait(&wrt);
   

    pthread_mutex_unlock(&mutex);

    printf("\n Reader: %d Data Read: %d\n", *(int *)i, cnt);

    pthread_mutex_lock(&mutex);
    NumberOfReaders--;
    if(NumberOfReaders==0)
 sem_post(&wrt);


    
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main()
{

    pthread_t readers[10] , writers[10];
    sem_init(&wrt,0,1);
    pthread_mutex_init(&mutex,NULL);

    
    int a[] = {1,2,3,4,5,6,7,8,9,10};
 
    for(int i=0;i<10;i++)
    {
        pthread_create(&writers[i],NULL,(void *) &writer,(void *) &a[i]);
        pthread_create(&readers[i],NULL,(void *) &reader,(void *) &a[i]);
    }
     
    for(int i=0;i<10;i++)
    {
        pthread_join(writers[i],NULL);
        pthread_join(readers[i],NULL);
    }
 
    sem_destroy(&wrt);
    pthread_mutex_destroy(&mutex);  
 
    return 0;
}

