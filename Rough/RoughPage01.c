#include <stdio.h>
#include <stdlib.h>

struct node
{
    char empName[50];
    int empID;
    struct node *next;
};

// struct node *readFromFile(const char *filename)
// {
//     FILE *file = fopen(filename, "r");
//     if (file == NULL)
//     {
//         perror("Error opening file");
//         exit(EXIT_FAILURE);
//     }

//     struct node *head = NULL;
//     struct node *current = NULL;

//     while (1)
//     {
//         struct node *newNode = (struct node *)malloc(sizeof(struct node));
//         if (newNode == NULL)
//         {
//             perror("Memory allocation failed");
//             exit(EXIT_FAILURE);
//         }

//         int result = fscanf(file, "%s %d", newNode->empName, &newNode->empID);

//         if (result != 2)
//         {
//             free(newNode);
//             break; // EOF or format error, break the loop
//         }

//         newNode->next = NULL;

//         if (head == NULL)
//         {
//             head = newNode;
//             current = newNode;
//         }
//         else
//         {
//             current->next = newNode;
//             current = newNode;
//         }
//     }

//     fclose(file);
//     return head;
// }

struct node * readFromFile(head){

    FILE *file = fopen("LinkedListFile", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

     struct node *head = NULL;
     struct node *current = NULL;
     struct node *newNode ;

    char buffer[100];

     while (fgets(buffer, sizeof(buffer), file) != NULL)
    {   // struct node *newNode = (struct node *)malloc(sizeof(struct node));

        // if(newNode==NULL){
        //     printf("Memory not allocated to newNode");
        // }



            char *key1 = strtok(buffer, "=");
            char *value1 = strtok(NULL, "=");

            if (key1 != 0 && value1 !=0)
            {
               strcpy(keyValuePair[i].key , key1);
                printf("%s",keyValuePair[i].key);

                strcpy(keyValuePair[i].value , value1);
                printf("%s",keyValuePair[i].value);

            }

            i++;
       
    }

    }

}

struct node *insertAtEnd(struct node *head)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
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

void displayOnConsole(struct node *head)
{
    int count = 1;

    struct node *temp = head;

    while (temp != NULL)
    {
        printf("Employee No. %d\t ", count);
        printf("%s\t ", temp->empName);
        printf("%d \n", temp->empID);

        temp = temp->next;
        count++;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    int choice;

    const char *filename = "LinkedListFile.txt"; // Modify with your file name
    head = readFromFile(filename);

    do
    {
        printf("\nLinked List Operations\n\n");
        printf("A. Insert \n");
        printf("\t2. Insert at end\n");
        printf("B. Display\n");
        printf("\t8. Display on Console\n\n");

        printf("D. Exit\n\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 2:
            head = insertAtEnd(head);
            break;

        case 8:
            displayOnConsole(head);
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
