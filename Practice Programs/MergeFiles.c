#include<stdio.h>

void main(){

    char ch;

    FILE *fptr1 , *fptr2 , *fptr3;

    fptr1 = fopen("MergeFiles1.txt" , "w");
    fptr2 = fopen("MergeFiles2.txt" , "w");
    fptr3 = fopen("MergeFiles3.txt" , "w");

    if(fptr1==0 || fptr2==0 || fptr3==0){
        printf("Files not created");
    }
    else{
        printf("Files created successfully");
    }


    fptr1 = fopen("MergeFiles1.txt" , "r");
    fptr2 = fopen("MergeFiles2.txt" , "r");
    fptr3 = fopen("MergeFiles3.txt" , "w");

    while( ch = fgetc(fptr1) != EOF ){
        fprintf(fptr1 , "File 1");
    }
    


 fclose(fptr1);
    fclose(fptr2);

    fclose(fptr3);
}






