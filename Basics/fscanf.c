#include<stdio.h>

int main() {
    char studentName[50];
    int studentID;
    float studentMarks;

    FILE *fPtr;

    fPtr = fopen("studentInfo.txt", "r");

    if (fPtr == NULL) {
        printf("File was not opened");
    }

    while (fscanf(fPtr, "%s %d %f", studentName, &studentID, &studentMarks) !=0 ) {
        printf("%s %d %f\n", studentName, studentID, studentMarks);
    }

    fclose(fPtr); 
    return 0;
}
