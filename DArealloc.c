#include <stdio.h>
#include <stdlib.h>

int *ptr;

void allocate(int n1)
{

    ptr = (int *)malloc(n1 * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < n1; i++)
    {
        printf("\nElement %d = %d\n", i + 1, ptr[i]);
    }
}

void reallocate(int n2)
{

    ptr = (int *)realloc(ptr, sizeof(int));

    for (int i = 0; i < n2; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        printf("Element %d = %d\n", i + 1, ptr[i]);
    }
}

void freePointer(){
    free(ptr);
}

int main()
{

    int num1;
    printf("How many elements do you want ?\n");
    scanf("%d", &num1);

    allocate(num1);

    int num2;
    printf("How many elements do you want ?\n");
    scanf("%d", &num2);

    reallocate(num2);

    freePointer();
    
    return 0;
}