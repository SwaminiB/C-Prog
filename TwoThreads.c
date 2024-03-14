#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
 
void *myThreadFunc1(void *var1){

sleep(5);

for(int i = 0 ;i<5; i++)
    printf("%d\n",i);

return NULL;
}

void *myThreadFunc2(void *var2){

sleep(3);

for(int i = 100 ;i<105; i++)
    printf("%d\n",i);

return NULL;
}

int main(){
 
pthread_t threadID1, threadID2;

pthread_create(&threadID1 , NULL , myThreadFunc1 , NULL);
pthread_create(&threadID2 , NULL , myThreadFunc2 , NULL);

pthread_join(threadID1 , NULL);
pthread_join(threadID2 , NULL);


return 0;
}