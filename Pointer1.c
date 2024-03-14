
// Create a pointer to the local variable n called pointer_to_n, and use it to increase the value of n by one.

#include <stdio.h>

void inc(int a){

    int *pointer_to_a = &a;

    printf("Value of pointer at a is : %d \n" , *pointer_to_a  );  //prints the value at pointer
    printf("Value stored in pointer is : %d\n" , pointer_to_a  );  //prints the address of a 
    printf("Value stored in pointer is : %d\n" ,&a );  //prints the address of a 
}

int main() {
    
    inc(5);
    return 0;
}