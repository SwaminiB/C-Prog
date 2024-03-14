#include<stdio.h>

void main(){

    char c;

    FILE *fptr;

    fptr = fopen("Question1.txt" , "r");

    // fptr = NULL;

    if(fptr == NULL){
        printf("File not created");
    }

    // fseek(fptr , 0 , SEEK_END);

    // printf("The length of file is : %d\n", ftell(fptr));

    c = fgetc(fptr);

    while( c != EOF){
        c = fgetc(fptr);
        printf("%c" , c);
    }

    fclose(fptr);

}