#include <stdio.h>
 
struct DBInfo {
    char DBname[50];
    char DBusername[50];
    char DBpassword[50];
    int server;
};
 
int main() {
    FILE *file;
    file = fopen("DBInformation.txt", "r");
    
    if (file == NULL) {
        printf("File not found or cannot be opened.\n");
        return 1;
    }
    
    int num;
    printf("How many onfigurations do you want to read?");
    scanf("%d", &num);
    
    struct DBInfo user[num];
    
    for (int i = 0; i < num; i++) {
        
        fscanf(file, "%s %s %s %d", user[i].DBname, user[i].DBusername, user[i].DBpassword, &user[i].server);

        printf("DBname: %s\n", user[i].DBname);
        printf("DBusername: %s\n", user[i].DBusername);
        printf("DBpassword: %s\n", user[i].DBpassword);
        printf("Server: %d\n", user[i].server);
    }
    
    fclose(file);
    
    return 0;
}