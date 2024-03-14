#include <stdio.h>

void main()
{

    char DBname[50];
    char DBusername[20];
    char DBpassword[20];
    int server;

    FILE *fptr;

    fptr = fopen("Struct.txt", "w");

    if (fptr == NULL)
    {
        printf("File was not created");
    }

    printf("Enter name");
    scanf("%s", &DBname);

    printf("Enter username");
    scanf("%s", &DBusername);

    printf("Enter password");
    scanf("%s", &DBpassword);

    printf("Enter server");
    scanf("%s", &server);

    fprintf( fptr , " DB Name : %s\n",DBname);

    fprintf( fptr , " DB UserName : %s\n",DBusername);

    fprintf( fptr , " DB Password : %s\n",DBpassword);

    fprintf( fptr , " Server : %s\n",&server);

    fclose(fptr);
}