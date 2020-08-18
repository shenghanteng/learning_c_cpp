#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    int income,disc;
    double tax, taxrate;
    scanf("%d", &income);
    if(income<=370000){
        taxrate = 0.06;
        disc = 0;
    }
    else if(income>370000 && income<=990000){
        taxrate = 0.13;
        disc = 25900;
    }
    else if(income>990000 && income<=1980000){
        taxrate = 0.21;
        disc=105100;
    }
    else if(income>1980000 && income<3720000){
        taxrate = 0.3;
        disc=283300;
    }
    else{
        taxrate = 0.4;
        disc=655300;
    }
    printf("income %d\n", income);
    printf("tax rate %.0f%%\n", taxrate*100);
    printf("tax %.0f\n", income*taxrate);
    printf("discount %d\n", disc);
    printf("taxpay %.0f\n", income*taxrate-disc);
    return 0;
}
