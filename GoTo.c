#include<stdio.h>

int main(){
 
printf("This is line 1\n");

goto label2;

printf("This line will not get executed");

label1:

printf("This is label 1\n");

label2:

printf("This is label 2\n");

label3:

printf("This is label 3\n");

return 0;
}