#include<stdio.h>

int main(){

    char arr[50];

    FILE *fptr;

    fptr = fopen("rewind.txt" , "r");

    while( fscanf(fptr , "%s" ,arr) != EOF){
        printf("%s" , arr);
    }


    rewind(fptr);

    while( fscanf(fptr , "%s" ,arr) != EOF){
        printf("%s" , arr);
    }

    fclose(fptr);
}