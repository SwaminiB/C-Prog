#include<stdio.h>

int main(){

    FILE *fptr;

    fptr = fopen("DeleteFile.txt" , "r");

    if(fptr == NULL){
        printf("File not created");
    }

    if( remove("DeleteFile.txt") == 0 ){
        printf("File deleted successfully");
    }
    else{
        printf("Unable to delete the file");
    }

    fclose(fptr);
}