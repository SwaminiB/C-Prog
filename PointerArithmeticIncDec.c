

    // -----INCREMENT AND DECRMENT-----
    

    int *ptr;
    int a[] = {10,20,30,40,50,60,70};

    ptr = &a[3];
        printf("Value of pointer: %d \n",*ptr);   //40

    // printf("Value of pointer Pre increment : %d \n",*++ptr);   // Pre increment //50
    // printf("Value of pointer: %d \n",*ptr);   //50

    printf("Value of pointer: %d and %d\n", *(++ptr) , *(ptr++));   

    // printf("Value of pointer Post increment : %d\n ",*ptr++);   // Post increment //40
    //  printf("Value of pointer: %d \n",*ptr);   //50
    
    // printf("Value of pointer Pre decrement : %d \n",*--ptr);   // Pre decrement //30
    //  printf("Value of pointer: %d \n",*ptr);   //30
    
    // printf("Value of pointer Post decrement : %d\n ",*ptr--);   // Post decrement //40
    //  printf("Value of pointer: %d \n",*ptr);   //30
    

