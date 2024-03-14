#include<stdio.h>

struct Info {
    char DBname[50];
    char DBusername[20];
    char DBpassword[20];
    int server;
};

void main(){

    struct Info person;

    FILE *fptr;

    fptr = fopen( "Struct.txt" , "r");

    while( fscanf( fptr , "%s\n%s\n%s\n%d" , person.DBname , person.DBusername , person.DBpassword , &person.server ) == 2){

        printf("%s\n%s\n%s\n%d" , person.DBname , person.DBusername , person.DBpassword , &person.server );
    }
    
}