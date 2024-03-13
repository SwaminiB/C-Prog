#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ARRAY 100

struct keyValue
{
    char *key;
    char *value;
} keyValuePair[MAX_ARRAY];

int setData()
{
    FILE *file;

    file = fopen("Configuration.txt", "r");

    if (file == NULL)
    {
        perror("File could not be opened");
        exit(1);
    }

    char buffer[100];
    int arrayEle = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        if (buffer[0] == '\n')
        {
            continue;
        }

        char *key1 = strtok(buffer, "=");

        char *value1 = strtok(NULL, "=");
            value1 = strtok(value1, " ");
            value1= strtok(value1 , "\n");

            

        if (key1 == NULL)
        {
            printf("Error:No key assigned");
        }

        if (key1 != NULL && value1 != NULL)
        {
            keyValuePair[arrayEle].key = (char *)malloc(sizeof(char));

            if (keyValuePair[arrayEle].key == NULL)
                printf("Memory allocation failed");

            key1 = strtok(buffer, " ");
            strcpy(keyValuePair[arrayEle].key, key1);

            keyValuePair[arrayEle].value = (char *)malloc(sizeof(char));

            if (keyValuePair[arrayEle].value == NULL)
                printf("Memory allocation failed");

            strcpy(keyValuePair[arrayEle].value, value1);

            arrayEle++;
        }
        else{
            printf("E");
        }
    }

    fclose(file);

    return arrayEle;
}

void getData(int arrayEle)
{

    for (int j = 0; j < arrayEle; j++)
    {

        printf("%s\t", keyValuePair[j].key);
        printf("%s\n", keyValuePair[j].value);
    }
}

void freeMemory(int arrayEle)
{
    for (int j = 0; j < arrayEle; j++)
    {
        free(keyValuePair[j].key);
        free(keyValuePair[j].value);
    }
}

int main()
{

    int num = setData();
    getData(num);
    freeMemory(num);

    return 0;
}