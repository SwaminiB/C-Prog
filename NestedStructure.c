#include <stdio.h>

struct studentInfo
{
    char name[50];
    int rollNo;
    int class;

    struct studentAddress
    {
        char area[50];
        char landmark[50];
        char city[50];
        char zipcode[10];
    } addr;
};

int main()
{
    int num;
    printf("How many students data do you want to save?");
    scanf("%d", &num);

    struct studentInfo s[num];

    for (int i = 0; i < num; i++)
    {
        printf("Enter name: ");
        scanf("%s", s[i].name);

        printf("Enter class: ");
        scanf("%d", &s[i].class);

        printf("Enter RollNumber: ");
        scanf("%d", &s[i].rollNo);

        printf("Enter Area: ");
        scanf("%s", s[i].addr.area);

        printf("Enter Landmark: ");
        scanf("%s", s[i].addr.landmark);

        printf("Enter City: ");
        scanf("%s", s[i].addr.city);

        printf("Enter Zipcode: ");
        scanf("%s", s[i].addr.zipcode);
    }

    for (int i = 0; i < num; i++)
    {
        printf("\nStudent %d Information \n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Class: %d\n", s[i].class);
        printf("RollNumber: %d\n", s[i].rollNo);
        printf("Area: %s\n", s[i].addr.area);
        printf("Landmark: %s\n", s[i].addr.landmark);
        printf("City: %s\n", s[i].addr.city);
        printf("Zipcode: %s\n", s[i].addr.zipcode);
    }

    return 0;
}