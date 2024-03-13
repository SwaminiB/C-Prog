#include <stdio.h>
#include <stdlib.h>

 int *sum(int *a, int *b)
{
    int *c;
    c = (int *)malloc(sizeof(int));
    *c = *a + *b;
    return c;
}

int main() {
    
    int num1 = 10;
    int num2=20;
    int *result = sum(&num1 , &num2);
    
    printf("Addition is %d\n", *result);
    printf("Address of result is %d\n", &result);

    result = NULL;
    free(result);

    return 0;
}