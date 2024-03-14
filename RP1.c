// Writer: Only one writer can write at a time
 
// Reader: 1.Multiple Reader's can read
//         2.Ensure no writer present while reading

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define MAX 5
 
 
int rc = 0; 
int cnt = 1; 
 
pthread_mutex_t mutex;
sem_t write;
 

void *writer(int *i)
{
    sem_wait(&write); // write-- 
    // cnt = rand() %10;
    cnt=cnt*2;
    printf("\n\n Writer: %d Item: %d",*(int *)i ,cnt);
    sem_post(&write); // write++
}
 
void *reader(int *i)
{
    pthread_mutex_lock(&mutex);
    rc++;

    if(rc == 1)
        sem_wait(&write); 
    pthread_mutex_unlock(&mutex);
 
    //  Critical Section
    printf("\n Reader: %d Data Read: %d",*(int *)i,cnt);
 
    pthread_mutex_lock(&mutex);
    rc--;
    if(rc == 0)
        sem_post(&write);
    pthread_mutex_unlock(&mutex);
}
 
 
int main()
{
    pthread_t wr[10],read[10];
    sem_init(&write,0,1);   
    pthread_mutex_init(&mutex,NULL);
 
    int a[] = {1,2,3,4,5,6,7,8,9,10};
 
    for(int i=0;i<10;i++)
    {
        pthread_create(&wr[i],NULL,(void *) &writer,(void *) &a[i]);
        pthread_create(&read[i],NULL,(void *) &reader,(void *) &a[i]);
    }
     
    for(int i=0;i<10;i++)
    {
        pthread_join(wr[i],NULL);
        pthread_join(read[i],NULL);
    }
 
    sem_destroy(&write);
    pthread_mutex_destroy(&mutex);  
 
    return 0;
}