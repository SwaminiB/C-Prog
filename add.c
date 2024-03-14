#include <stdio.h>
int main() {    

    int number1, number2, sum;
    
    printf("Enter integer 1: ");
    scanf("%d", &number1);

    printf("Enter integer 2:");
    scanf("%d",&number2);
    
    // calculate the sum
    sum = number1 + number2;     

    printf("%d + %d = %d", number1, number2, sum);
    return 0;
}