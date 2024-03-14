#include<stdio.h>
#include<unistd.h>

int main(){

int n;
char buffer[30];
n = read(0,buffer,30);  //total number of char read
write(1,buffer,n);


return 0;
}