// #include <stdio.h>
// #include <time.h>

// int main()
// {
//     // Declaring variables to store time information
//     time_t rawtime;         // Raw time, representing the number of seconds since the Epoch (1970-01-01 00:00:00 +0000 UTC)
//     struct tm* timeinfo;    // Structure to store time broken down into components

//     // Used to store the formatted time string
//     char buffer[80];

//     // Get the current raw time
//     time(&rawtime);

//     // Convert the raw time to local time and store it in the timeinfo structure
//     timeinfo = localtime(&rawtime);

//     // Format the time using strftime() and store it in the buffer
//     strftime(buffer, 80, "Time is %I:%M%p.", timeinfo);

//     // Print the formatted time
//     puts(buffer);

//     return 0;
// }


#include<stdio.h>
#include<time.h>

int main(){
 
struct tm *ptr;
time_t t;

t = time(NULL);

ptr=localtime(&t);

char buffer[50];

 strftime(buffer, 80, "The time now is %I:%M%p.", ptr); // strftime() function stores the current time as Hours : Minutes%I %M and %p-> format specifier of Hours minutes and am/pm respectively*/
 
puts(buffer);

return 0;
}