#include <stdio.h>
 
void starPattern(int no){
    
    for(int i=1;i<=no;i++){
        printf("*\t");
    }
    printf("\n");
    
    for(int i=1;i<no-1;i++){
    
    for(int j=1;j<=(no-i-1);j++){
        printf("\t");
    }
    
    printf("*\n");
    }
     for(int i=1;i<=no;i++){
        printf("*\t");
    }
}
 
int main()
{
    int no;
    printf("Enter the number of stars to form Z");
    scanf("%d",&no);
    
    if(no%2==0){
        printf("Please enter any odd number.");
    }
    else{
    starPattern(no);
    }
    return 0;
}