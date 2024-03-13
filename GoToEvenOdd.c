#include <stdio.h>

int main()
{

    int number;

    printf("Enter any number");
    scanf("%d", &number);


    if (number % 2 == 0)
    {
        goto even;
    }
    else
    {
        goto odd;
    }

even:

    printf("Number is Even\n");
    printf("The multiplication table of %d :", &number);

    for (int i = 1; i <= 10; i++)
    {

        printf("%d * %d = %d\n ", number, number, (number * i));
    }
    return 0;

odd:

        printf("Number is Odd\n");

        
   
    return 0;
}