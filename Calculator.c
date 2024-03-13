#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *sum(int *a, int *b)
{
    int *c;
    c = (int *)malloc(sizeof(int));
    *c = *a + *b;
    return c;
}

int *subtract(int *a, int *b)
{
    int *c;
    c = (int *)malloc(sizeof(int));
    *c = *b - *a;
    return c;
}

int *multiply(int *a, int *b)
{
    int *c = (int *)malloc(sizeof(int));
    *c = (*a) * (*b);
    return c;
}

int *divide(int *a, int *b)
{
    int *c = (int *)malloc(sizeof(int));

    if ((*a == 0) || ((*b) == 0))
    {
        printf("Error! Division by zero is not allowed.\n");
    }
    else
    {
        *c = (*a) / (*b);
    }
    return c;
}

int factorial(int *a)
{
    int fact = 1;

    for (int i = 1; i <= (*a); i++) // Start from 1
    {
        fact = fact * i;
    }
    return fact;
}

// int *power(int *a, int *b)
// {
//     int *c = (int *)malloc(sizeof(int)); // Change sizeof(float) to sizeof(int)
//     *c = pow(*a, *b);
//     return c;
// }

int main()
{
    int num1, num2, op, choice;
    int *result;

    do
    {
        result = (int *)malloc(sizeof(int)); // Allocate memory inside the loop

        printf("\t\tCalculator Program \n");

        printf("Enter number 1: ");
        scanf("%d", &num1);

        printf("Enter number 2: ");
        scanf("%d", &num2);

        printf(" Enter the operation to perform\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Power\n6.Factorial\n");
        scanf("%d", &op); // Change %c to %d

        switch (op)
        {
        case 1:
            *result = *sum(&num1, &num2);
            printf("Addition is %d\n", *result);
            break;

        case 2:
            *result = *subtract(&num1, &num2);
            printf("Subtraction is %d\n", *result);
            break;

        case 3:
            *result = *multiply(&num1, &num2);
            printf("Multiplication is %d\n", *result);
            break;

        case 4:
            *result = *divide(&num1, &num2);
            printf("Division is %d\n", *result);
            break;

        // case 5:
        //     *result = *power(&num1, &num2);
        //     printf("Power is %d\n", *result);
        //     break;

        case 6:
            printf("Do you want factorial of number 1 or number 2? (1/2): ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                *result = factorial(&num1);
                printf("Factorial of number 1 is %d\n", *result);
            }
            else
            {
                *result = factorial(&num2);
                printf("Factorial of number 2 is %d\n", *result);
            }
            break;
        }

        free(result); // Free the allocated memory

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &choice);

    } while (choice == 1);

    return 0;
}
