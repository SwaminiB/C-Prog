#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
 
void *myThreadFunc(void *var){

    int *ptr  = (int*)malloc(sizeof(int));
    *ptr = 10;

    for(int i=0 ;i<20;i++){
        printf("The value of ptr is %d\n",*ptr);
        (*ptr)++;
    }

sleep(3);

return ptr;
}

int main(){
 
int *result; 

pthread_t threadID;
pthread_create(&threadID , NULL , myThreadFunc , NULL);
pthread_join(threadID, (void*)&result);

printf("Thread's done: result = %d\n",*result);


return 0;
}