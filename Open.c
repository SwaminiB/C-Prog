#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{

    int n, fd;

    char buf[100];


    fd = open("test.txt", O_RDONLY);

    n = read(fd , buf, 10);

    write(1 , buf , 10);

    return 0;
}