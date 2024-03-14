#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
 
int n , fd , fd1;
char buf[30];

fd = open("test.txt" , O_RDONLY);
n = read(fd , buf , 30);

fd1 = open("target.txt" ,  O_CREAT | O_WRONLY , 0642);
write(fd1,buf ,n);

return 0;
}