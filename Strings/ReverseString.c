// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * reverseString( char *str){
    
    int length = strlen(str) - 1;
    int j=0;
    
    char * reverseStr = (char *) malloc(length * sizeof(char));
    
    if (reverseStr == NULL)
    {
        printf("Memory allocation failed.\n");
    }
    else{
        
    for(int i = length ; i>=0 ; i--){
        reverseStr[j] = str[i];
        j++;
    }
     reverseStr[j]='\0';

    }
    
    return reverseStr;
  
}
int main() {
    
    char arr[] = "Cybage Software";
    
    char * result = reverseString(arr);
    
    printf("Input String before Reversing : %s\n",arr);
    printf("\nOutput String after Reversing : %s\n",result);
    
    return 0;
}