#include <stdio.h>
#include <time.h>

int main()
{

    struct tm *ptr; // holds date and timed

    time_t t; // clock time as an int

    t = time(NULL); // calender time return karega
    ptr = localtime(&t);
    printf("%s", asctime(ptr)); // returns date and time  in the format day month date hours:minutes:seconds year
    return 0;
}