#include <stdio.h>

// All the code ie instructions go into the code/text segment

int b = 34;        //global/static block

int mult(){
    return 3*3;
}

int func1(int b){
    static int myvar = 45;
    printf("The value of myvar is : %d\n",myvar);
    myvar++;
    return (b + myvar) ;
}

int main() {
    
    int b =20;

    int value = func1(b);
    value = func1(b);
    value = func1(b);
    value = func1(b);
    value = func1(b);

    int *ptr = &value;

   


    return 0;
}