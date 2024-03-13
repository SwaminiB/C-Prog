#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct employee
{
    char empName[50];
    int empID;
    struct employee *next;
};

void displayLinkedList(struct employee *head)
{
    struct employee *current = head;
    int employeeNumber = 1;

    while (current != NULL)
    {
        printf("Employee No. %d: Name: %s, ID: %d\n", employeeNumber, current->empName, current->empID);
        current = current->next;
        employeeNumber++;
    }
}

int readFromFile()
{

    FILE *file = fopen("LinkedListFile.txt", "r"); 
    if (file == NULL)
    {
        perror("Error opening file");
        return 1; 
    }

    char buffer[100];

    struct employee *head = NULL;
    struct employee *current = NULL;

    int empID;
    char empName[50];

    while( fgets(buffer , 100 , file) != NULL){

        char *empName1 =  strtok("buffer" , ",");
        char *empID1 = strtok("NULL",",");

        if(empName1 !=0 && empID1 != 0){

        struct employee *newEmployee = (struct employee *)malloc(sizeof(struct employee));

        strcpy((newEmployee->empName),(empName1));
        newEmployee->empID = empID1;
        newEmployee->next=NULL;

        if (head == NULL)
        {
            head = newEmployee;
            current = newEmployee;
        }
        else
        {
            current->next = newEmployee;
            current = newEmployee;
        }

        }
    }


    fclose(file);

   
    displayLinkedList(head);

    while (head != NULL)
    {
        struct employee *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
     struct node *head = NULL;

     readFromFile(head);
    return 0;
}