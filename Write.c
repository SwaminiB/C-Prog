#include<stdio.h>
#include<unistd.h>

int main(){
 
int n;

n = write(1,"Hello!\n",7);

printf("Value of n : %d",n);

return 0;
}