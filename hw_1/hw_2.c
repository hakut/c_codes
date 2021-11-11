/**
 * This program is written for decimal conversion of a binary input
 * 
**/
#include <stdio.h>

int main(){
    unsigned int fac_entry, fac_output,temp;
    while(1){
        fac_output = 1;
        printf("Enter a number to take its factorial (-1 to exit) : ");
        scanf("%d",&fac_entry);
        if(fac_entry == -1){
            break;
        }
        temp = fac_entry;
        while(temp > 0){
            fac_output *= temp;
            temp--;
        }
        printf("Factorial of %d is : %d\n",fac_entry, fac_output);

    }
    return 0;
}