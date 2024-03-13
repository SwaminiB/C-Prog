#include<stdio.h>
#include<errno.h>

int main(){

    FILE *file;

    file = fopen("ErrorHandling.txt" , "r");

    printf("Value of error is : %d\n",errno); 

    return 0;


}