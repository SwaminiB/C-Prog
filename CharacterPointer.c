#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void iterate(char *str) {
    int i = 0;
    printf("\nThe value at str is:");
    while (*(str + i) != '\0') {
        printf("%c", *(str + i));
        i++;
    }
}

// void assignToArrayWithoutUsingStrlen(char *str, char A[]) {
//     int i = 0;
//     printf("\nValue of str is copied into array without using strlen is: \n");
//     while (*(str + i) != '\0') {
//         A[i] = *(str + i);
//         printf("%c", A[i]);
//         i++;
//     }
// }

// void assignToArrayUsingStrlen(char *str, char A[]) {
//     int length = strlen(str);
//     printf("\nLength of value at strlen is: %d\n", length);
//     printf("\nValue of str is copied into array using strlen is:\n");

//     for (int i = 0; i < length; i++) {
//         A[i] = str[i];
//         printf("%c", A[i]);
//     }
// }

void strLength(char *str1 , char* str2){
    // Iterating through the first string and appending characters from second string to it.

    int length1=0;
    int length2 =0;

    while(*(str1+length1)!= '\0'){
        length1++;
   }

    while (*(str2 + length2) != '\0'){
       length2++;
    }
        
    printf("The length of string 1 is%d",length1);
    printf("The length of string 2 is%d",length2);

}

// char * concatenation( char *s1,  char *s2) {

//     size_t len1 = strlen(s1);
//     size_t len2 = strlen(s2);

//     char *result = malloc(len1 + len2 + 1);  

//     strcpy(result, s1);                                          
//     strcpy(result + len1, s2);               
//     return result;
// }

char * concatenate(char * str1 , char * str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);

    char * newStr = (char*) malloc (length1+length2+1);

    newStr = strcpy(newStr , str1);
    newStr = (newStr+length1 ,  " ");
    newStr = strcat(newStr , str2);

    return newStr;
}

int main() {

    int maxLength = 100, choice, cont;
    char name[10];
    char *string;

    do {
        char string1 = (char *)malloc(maxLength * sizeof(char));
        char string2 = (char *)malloc(maxLength * sizeof(char));

        printf("Enter the string1: ");
        scanf(" %s", string1); // Use %s for string input

        printf("Enter the string2: ");
        scanf(" %s", string2); // Use %s for string input


        printf("\nMenu : ");
        printf("\nPress 1 to copy string into an array without using strlen function.");
        printf("\nPress 2 to copy string into an array using strlen function.");
        printf("\nPress 3 to find lenght of the two strings");
        printf("\nPress 4 to concatenate the two strings");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            iterate(string);
            break;

        case 2:
            assignToArrayUsingStrlen(string, name);
            break;

        case 3:
            assignToArrayWithoutUsingStrlen(string, name);
            break;

         case 4:
            concatenate(string, name);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &cont);

        free(string); // Free allocated memory

    } while (cont == 1);

    return 0;
}
