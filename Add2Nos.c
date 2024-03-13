#include<stdio.h>
#include<time.h>

int main(){
 

 struct tm *ptr;
 time_t start,end;

 start = time(NULL);
 int num1,num2;

printf("Enter number 1\n");
scanf("%d",&num1);
printf("Enter number 2\n");
scanf("%d",&num2);

int result = num1+num2;

printf("The addition is : %d\n",result);

end = time(NULL);

printf("The taken to print the addition is : %.4f seconds\n", difftime(end,start));



return 0;
}