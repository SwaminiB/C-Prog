#include <stdio.h>
#include "ExternalLinkage1.c"
#include "ExternalLinkage2.c"
#include "ExternalLinkage3.c"


void googlePay( int gpAmount);
void debitCardPay( int dcAmount);

int main(){
    
      googlePay(2000);
      debitCardPay(1000);
     return 0;
}

