#include <stdio.h>
#include<stdlib.h>

int *ptr;

void createArray(int n){

    ptr = (int*) calloc (n , sizeof(int));

    if(ptr==NULL){
        printf("Memory not allocated\n");
    }

    else{
        printf("Memory allocated\n");
    }
}

void display(int n){
    for(int i=0 ;i<n; i++){
        printf("%d\t",*ptr);
}
}

int main() {
    
     int n;
    printf("How many elements do you want ?\n");
    scanf("%d", &n);

    createArray(n);
    display(n);
    return 0;
}