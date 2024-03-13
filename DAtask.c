#include <stdio.h>
#include <stdlib.h>

void func1(int var ){

    int i = 0;
   char *ptr;
    int idLength;

 while(i<var){
      
   
    printf("Employee %d : Enter the length of your name : \n",i+1); 
    scanf("%d", &idLength);

    ptr = (char*) malloc ((idLength+1)*sizeof(char));

     printf("Enter Employee Name:");
     scanf("%s", ptr);
printf("----------------------------------------------------\n");
    printf(" Employee Name: %s\n", ptr);

printf("----------------------------------------------------\n");
    free(ptr);
    i++;
    
  }     
}

int main()
{
    int a;
  
  printf("\nEnter the number of your Employees you want to store :\n "); 
    scanf("%d", &a);
  
  func1(a);
 
    
    return 0;
}
