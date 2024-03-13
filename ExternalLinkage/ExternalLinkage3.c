#include <stdio.h>

extern int nBalancedAmount;


void googlePay( int gpAmount) {
    
    nBalancedAmount = nBalancedAmount - gpAmount;

    printf("Bank Balance : %d\n",nBalancedAmount);
}
