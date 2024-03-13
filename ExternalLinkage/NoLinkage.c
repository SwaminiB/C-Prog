#include <stdio.h>

void funct1(){
    int amount1 = 50000;
    printf("Amount 1 is: %d\n",amount1);
}

void funct2(){
    int amount2 = 250000;
    printf("Amount 2 is: %d",amount2);
}
int main() {
    funct1();
    funct2();
    return 0;
}