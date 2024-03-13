#include <stdio.h>
#include <string.h>

int main()
{

    struct keyValue
    {
        char key[100];
        char value[100];
    };

    int num = 10;
    struct keyValue keyValuePair[num];

    FILE *file;

    file = fopen("Configuration.txt", "r");

    if (file == NULL)
    {
        printf("File could not be opened");
    }

    char buffer[100];
    int i = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
            char *key1 = strtok(buffer, "=");
            char *value1 = strtok(NULL, "=");

            if (key1 != 0 && value1 !=0)
            {
               strcpy(keyValuePair[i].key , key1);
                printf("%s",keyValuePair[i].key);

                strcpy(keyValuePair[i].value , value1);
                printf("%s",keyValuePair[i].value);

            }

            i++;
       
    }
        return 0;
    }