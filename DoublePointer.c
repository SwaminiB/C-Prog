#include <stdio.h>
int main() {
    int a = 10;

    int *ptr1 = &a;

    printf("Address of ptr1 is : %d\n",ptr1);
    printf("Value of ptr1 is : %d\n",*ptr1);

    int **ptr2 = &ptr1;

    printf("Address of ptr2 is : %d\n",ptr2);
    printf("Value of ptr2 is : %d\n",*ptr2);

    return 0;
}