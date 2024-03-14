#include<stdio.h>

int main(){

    int i = 0;

    FILE *fptr;

    fptr = fopen("EvenOddRewind.txt" , "r");

    if(fptr == NULL){
        printf("File was not created");
    }

    printf("Even Numbers are\n");

    while( fscanf(fptr , "%d" , &i ) != EOF ){
        if(i%2==0)
        printf("%d\n",i);
    }

    rewind(fptr);

    printf("Odd Numbers are\n");

    while( fscanf(fptr , "%d" , &i ) != EOF ){
        if(i%2 != 0)
        printf("%d\n",i);
    }
    
    fclose(fptr);

}