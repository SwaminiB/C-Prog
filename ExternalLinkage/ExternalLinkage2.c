#include <stdio.h>

extern int nBalancedAmount;


void debitCardPay( int dcAmount) {
    
    nBalancedAmount = nBalancedAmount - dcAmount;

    printf("Bank Balance : %d\n",nBalancedAmount);
    
}

