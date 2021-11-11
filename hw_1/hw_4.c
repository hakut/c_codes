/**
 * This program is written for decimal conversion of a binary input
 * 
**/
#include <stdio.h>

unsigned int factorial(unsigned int value){
    unsigned int ret = 1;
    while(value > 0){
        ret *= value;
        value--;
    }
    return ret;
}

unsigned int power(unsigned int value, unsigned int pow){
    unsigned int ret = 1;
    while(pow > 0){
        pow--;
        ret *= value;
    }
    return ret;
}

int main(){
    while(1){
    float e = 1;
    unsigned int coefficient = 1, entry, pow;
    printf("Please enter a number to determine the precition of formula : ");
    scanf("%d",&entry);
    printf("Please enter the power of e : ");
    scanf("%d",&pow);

    if(entry == -1){
        break;
    }
    while(coefficient < entry){
        e +=  (float)power(pow,coefficient)/factorial(coefficient);
        coefficient++;
    }
    printf("%f\n",e);
    }
    return 0;
}