#include <stdio.h>
#define MAX_SIZE 100

struct keyValuePair{
    char key[MAX_SIZE];
    char value[MAX_SIZE];
}keyValue;

int main() {
    
    FILE *file;
    file = fopen("Configuration.txt", "r");
    
    if (file == NULL) {
        printf("File not found or cannot be opened.\n");
        return 1;
    }
    
    int count = 0;

    while (fscanf(file, " %[^=] = %s ", keyValue.key, keyValue.value) != EOF) {

        printf("%s = %s\n",  keyValue.key, keyValue.value);

        count++;

        if(count%4 == 0){
            printf("\n");
        }
    }
 
    fclose(file);
 
    return 0;
}
