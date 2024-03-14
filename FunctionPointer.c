#include <stdio.h>

int sum(int a, int b){
    return a+b;
}

void main() {
    int s;

    int (*ptr)(int , int) = sum;
   
   s = (*ptr)(55,36);

   printf("The sum is : %d",s);
}