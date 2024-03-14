#include<stdio.h>

int main(){

    FILE *fptr;

    char ch;

    char str[50]; 

    int pos;

    fptr = fopen("rewind.txt" , "r");

    if(fptr ==NULL ){
        printf("Error creating the file");
    }

    pos = ftell(fptr);

    printf("The pointer is at position : %d\n",pos);

    fseek(fptr , 5 , SEEK_SET);

    ch = fgetc(fptr);

    printf("The pointer is at postion %d and char is : %c\n", ftell(fptr) , ch);

    fscanf(fptr , "%s" , str);

    printf("%s\n" , str);

    printf("The position of file pointer is : %d \n", ftell(fptr));   

    fseek(fptr , 0 , SEEK_END);

    printf("The length of file is %d\n" , ftell(fptr)); 

    fclose(fptr);


}