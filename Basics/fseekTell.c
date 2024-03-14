#include<stdio.h>

// void main(){

//     FILE *fptr;

//     char a;

//     fptr = fopen("rewind.txt" , "r");

//     fseek(fptr , 3, SEEK_SET);

//     a = getc(fptr);

//     printf("In location %d the char is %c" , ftell(fptr) , a);

//     fclose(fptr);
// }

#include <stdio.h>

int main() {

    FILE *fptr = NULL;
    char ch;

    fptr = fopen("rewind.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file");
    }

    // if (fseek(fptr, 3, SEEK_SET) != 0) {
    //     perror("Error seeking in file");
    //     fclose(fptr);
    //     return 1;
    // }

    fseek(fptr , 14 , SEEK_SET);

    ch = fgetc(fptr);

    printf("The char is %c\n", ch);

    fseek(fptr , -4 , SEEK_CUR);

    ch = fgetc(fptr);

    printf("The char after SEEK_CUR is : %c\n",ch);

    fseek(fptr , -3 , SEEK_END);

    ch = fgetc(fptr);

   printf("The char after SEEK_END is : %c\n",ch);

    fclose(fptr);
    return 0;
}
