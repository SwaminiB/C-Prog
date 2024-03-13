#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strLength(char *str1, char *str2)
{
    // Iterating through the first string and appending characters from second string to it.

    int length1 = 0;
    int length2 = 0;

    while (*(str1 + length1) != '\0')
    {
        length1++;
    }

    while (*(str2 + length2) != '\0')
    {
        length2++;
    }

    printf("The length of string 1 is%d", length1);
    printf("The length of string 2 is%d", length2);
}

char *copyStr(char *str1, char *str2) {
    int length = strlen(str1) + strlen(str2) + 2;  // +2 for space and null terminator
    char *newString = (char *)malloc(sizeof(char) * length);
    
    strcpy(newString, str1);
    strcat(newString, " ");
    strcat(newString, str2);
 
    printf("%s", newString);
    return newString;
}
// char *copyStr(char *str1, char *str2)
// {

//     int length = (strlen(str1)) + (strlen(str2)) + 2;
//     char *newString = malloc(sizeof(char) * (length));

//     for (int i = 0; i < strlen(str1); i++)
//     {
//         newString[i] = *(str1 + i);
//     }

//     newString = strcat(newString, " ");

//     int len1 = strlen(str1);
//     int len2 = strlen(str2);

//     for (int i = 0; i <= len2; i++)
//     {
//         newString[len1] = str2[i];
//         len1++;
//     }
//     // printf("%s", newString);

//     return newString;
// }

// void print_string(char *str)
// {
//     if (!str)
//     {
//         printf("NULL");
//         return;
//     }

//     while (*str != '\0')
//     {
//         printf("%c", *str);
//     }
// }

int main()
{

    int maxLength = 100, choice, cont;
    char *string1, *string2;

    do
    {
        string1 = (char *)malloc(maxLength * sizeof(char));
        string2 = (char *)malloc(maxLength * sizeof(char));

        printf("Enter the string1: ");
        scanf(" %s", string1); // Use %s for string input

        printf("Enter the string2: ");
        scanf(" %s", string2); // Use %s for string input

        printf("\nMenu : ");
        printf("\nPress 1 to find lenght of the two strings");
        printf("\nPress 2 to concatenate the two strings");
        printf("\nPress 3 to copy the string into another  string");
        // printf("\nPress 4 to compare two strings \n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            strLength(string1, string2);
            break;

        case 2:
            // print_string(concatenate(string1, string2));
            concatenateStr(string1, string2);
            break;

        case 3:

            char *copyString;
            copyString = copyStr(string1, string2);
            printf("\nCopied String is :%s\n", copyString);
            free(copyString);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &cont);

        free(string1); // Free allocated memory
        free(string2); // Free allocated memory

    } while (cont == 1);

    return 0;
}
