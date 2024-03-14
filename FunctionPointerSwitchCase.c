#include <stdio.h>

void add(int a , int b){
    printf("Addition is : %d",(a+b));
    }

void subtract(int a , int b){
    printf("Subtraction is : %d",(a+b));
    }

void multiply(int a , int b){
     printf("Multiplication is : %d",(a+b));
    }

void divide(int a , int b){
     printf("Division is : %d",(a+b));
    }

int main() {
    

    int choice,num1,num2;
    printf("\nEnter the first number: ");
    scanf("%d",&num1);
    printf("\nEnter the second number: ");
    scanf("%d",&num2);

    printf("\nSelect operation:\n 1. Add\n 2. Subtract\n 3. Multiply\n 4. Divide");
    printf("\nEnter your choice ");\
    scanf("%d",&choice);

    void (*funcPointer[10])(int , int) = {add , subtract , multiply , divide}; 
    (*funcPointer[choice])(num1,num2);      //Replacement of switch case

    return 0;
}