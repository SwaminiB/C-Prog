#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
 
void *myThreadFunc1(void *var){

sleep(5);

printf("hi from thread 1\n");

return NULL;
}


int main(){
 
pthread_t threadID1;


printf("before thread\n");

pthread_create(&threadID1 , NULL , myThreadFunc1 , NULL);


pthread_join(&threadID1 , NULL);


printf("after creating a thread\n");

return 0;
}