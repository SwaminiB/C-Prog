#include <stdio.h>
#include <stdlib.h>

// ----------MALLOC----------

int *ptr;

void createArray(int leng)
{

    ptr = (int *)malloc(leng * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed");
    }
    else
    {
        printf("Memory allocated successfully\n");
    }
}

void display(int leng)
{

    for (int i = 0; i < leng; i++)
    {
        printf("Value of array at index %d is : %d \n", (i),(i + 1));
    }
}

void deleteArray()
{
    free(ptr);
}

int main()
{

    int n;
    printf("How many elements do you want ?");
    scanf("%d", &n);

    createArray(n);
    display(n);
    deleteArray();
    return 0;
}