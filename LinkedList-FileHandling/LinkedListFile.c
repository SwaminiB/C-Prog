#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char empName[50];
    int empID;
    struct node *next;
};

struct node *insertAtBeginning(struct node *head)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter the ID to be inserted (beg) : ");
    scanf("%d", &newnode->empID);
    printf("Enter the name to be inserted (beg) : ");
    scanf("%s", newnode->empName);

    newnode->next = head;
    return newnode;
}

struct node *insertAtEnd(struct node *head)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter the ID to be inserted (end) : ");
    scanf("%d", &newnode->empID);
    printf("Enter the name to be inserted (end) : ");
    scanf("%s", newnode->empName);
    newnode->next = NULL;

    if (head == NULL)
    {
        return newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        return head;
    }
}

struct node *insertAtIndex(struct node *head)
{

    struct node *newnode;
    int position, count = 0, i = 0;

    struct node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    printf("The length  of the list is %d\n", count);

    printf("Enter the position after which you want to insert: ");
    scanf("%d", &position);

    if (position > count)
    {
        printf("\nThe given position is more than the number of elements in Linked List\n");
    }
    else
    {

        temp = head;

        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }

        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter the ID to be inserted (index) : ");
        scanf("%d", &newnode->empID);
        printf("Enter the name to be inserted (index) : ");
        scanf("%s", newnode->empName);

        newnode->next = temp->next;
        temp->next = newnode;

        return head;
    }
}

struct node *deleteAtbeginning(struct node *head)
{
    // struct node* temp;

    if (head == NULL)
    {
        printf("\n The linked list is empty.\n");
    }

    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

struct node *deleteAtEnd(struct node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
    }

    else if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {

        struct node *temp = head;
        struct node *prevNode = NULL;

        while (temp->next != NULL)
        {
            prevNode = temp;
            temp = temp->next;
        }

        prevNode->next = NULL;

        free(temp);
    }
    return head;
}

struct node *deleteAtIndex(struct node *head)
{
    struct node *temp = head;
    struct node *nextNode;
    int pos, i = 0;

    int count = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    printf("The length  of the list is %d\n", count);

    printf("Enter the position after which you want to delete a node: ");
    scanf("%d", &pos);

    if (head == NULL || pos < 0)
    {
        printf("Inavlid input! Please enter a valid position.");
    }

    temp = head;

    if (pos == 0)
    {

        free(temp);
    }

    else
    {

        while (i < pos)
        {
            temp = temp->next;
            i++;
        }

        nextNode = temp->next;
        temp->next = nextNode->next;

        free(nextNode);

        return head;
    }
}

void displayOnConsole(struct node *head)
{
    int count = 1;

    struct node *temp = head;

    while (temp != NULL)
    {
        // printf("Employee No. %d\t ", count);
        printf("%s,", temp->empName);
        printf("%d,\n", temp->empID);

        temp = temp->next;
        count++;
    }
    printf("\n");
}

void saveToFile(struct node *head)
{
    FILE *file;
    file = fopen("LinkedListFile.txt", "w");

    if (file == NULL)
    {
        printf("File not found or cannot be opened.\n");
        return;
    }

    struct node *temp = head;
    int count = 1;

    while (temp != NULL)
    {
        // fprintf(file, "Employee No. %d\t", count);
        fprintf(file, "%s,", temp->empName);
        fprintf(file, "%d,\n", temp->empID);

        temp = temp->next;
        count++;
    }

    fclose(file);
}

struct node *readFromFile(struct node *head)
{

    FILE *file = fopen("LinkedListFile.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
       
    }

    // head = NULL;
    struct node *current = NULL;

    int empID1;
    char empName1[50];
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {

        char *empName1 = strtok(buffer, ",");
        char *empID1 = strtok(NULL, ",");

        if (empName1 != 0 && empID1 != 0)
        {

            struct node *newEmployee = (struct node *)malloc(sizeof(struct node));

            strcpy((newEmployee->empName), (empName1));
            newEmployee->empID = atoi(empID1);
            newEmployee->next = NULL;

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
    return head;
}

int main()
{
    struct node *head1 = NULL;
    struct node * head = NULL;
    int choice;
    head = readFromFile(head1);   

    do
    {
        printf("\nLinked List Operations\n\n");
        printf("A. Insert \n");
        printf("\t1. Insert at beginning\n");
        printf("\t2. Insert at end\n");
        printf("\t3. Insert at given index\n");
        printf("B. Delete\n");
        printf("\t4. Delete at beginning\n");
        printf("\t5. Delete at end\n");
        printf("\t6. Delete at given index\n\n");
        printf("7. Display on Console\n\n");
        printf("8. Save to File \n\n");
        
        printf("D. Exit\n\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = insertAtBeginning(head);
            break;

        case 2:
            head = insertAtEnd(head);
            break;

        case 3:
            head = insertAtIndex(head);
            break;

        case 4:
            head = deleteAtbeginning(head);
            break;

        case 5:
            head = deleteAtEnd(head);
            break;

        case 6:
            head = deleteAtIndex(head);
            break;


        case 7:
            displayOnConsole(head);
            break;

        case 8:
            saveToFile(head);
            break;


        case 0:
            while (head != NULL)
            {
                struct node *temp = head;
                head = head->next;
                free(temp);
            }
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
