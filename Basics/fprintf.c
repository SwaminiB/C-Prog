#include<stdio.h>

int main(){

    char stdName[50];
    int stdID;
    float stdMarks;

    printf("Enter student name");
    scanf("%s",&stdName);

    printf("Enter student ID");
    scanf("%s",&stdID);

    printf("Enter student marks");
    scanf("%f",&stdMarks);

    FILE *fPtr ;

    fPtr = fopen("studentInfo.txt" , "a");

    if(fPtr == NULL){
        printf("File not created");
    }

    else{

        // fprintf(fPtr , "Student Name: %s \n Student ID: %d \n Student Marks: %f\n", stdName , stdID , stdMarks);
    

        fprintf(fPtr , " %s\t  %d\t  %f\n", stdName , stdID , stdMarks);

    }

    fclose(fPtr);
    
}