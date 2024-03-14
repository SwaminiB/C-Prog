#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
 
int n , fd , fd1;
char buf[100];

fd = open("test.txt" , O_RDONLY);
n = read(fd , buf , 100);

fd1 = open("target1.txt" ,  O_APPEND| O_WRONLY );
write(fd1,buf ,n);

return 0;
}