#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
 
int n , fd , fd1;
char buf[100];

fd = open("test.txt" , O_RDONLY);
n = read(0 , buf , 100);

fd1 = open("target1.txt" ,  O_CREAT | O_WRONLY , 0642);
write(fd1,buf ,n);

// if (close(fd1) < 0) {
//         perror("c1");
//         return 0;
//     }
//     printf("closed the fd.\n");

return 0;
}