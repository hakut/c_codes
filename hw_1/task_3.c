/**
 * This program is written for estimation of number e
 * 
**/
#include <stdio.h>

/**
 * @brief This function calculates the factorial of passed parameter
 * 
 * @param value 
 * @return int 
 */
int factorial(int value){
    if(value == 0){ // If value is 0 than factorial is 1
        return 1;
    }

    /* This part of the code is recursive. It passes the one less value
        to the function and runs the function again and every return value
        multiplied by the previous one. Just like how factorial works.
    */
    return(value * factorial(value - 1));
}

/**
 * @brief Main function gets the input from the user and use this input to
 * Determine the precision of calculation. Also we use 1 as e init value 
 * and we summate the e with 1 over factorial of increasing counter, which
 * its final value is determined by user input. So that we get estimated e value
 * 
 * @return int 
 */
int main(){
    while (1) {
        float e = 1; // e value initialization
        int coefficient = 1,precision,is_type_correct; // Init coefficient value to 1 and define precision

        start:

        printf("Please enter a number to determine the precition of formula (-1 to exit): ");
        is_type_correct = scanf("%d",&precision); // Gets user input
        fflush(stdin);
        
        if (is_type_correct == 0) { // If not integer go to start
            goto start;
        }

        // According to my try and error best precision value is 12-13
        if (precision == -1) { // If input is -1 exit program
            break;
        }

        for ( ; coefficient < precision ; coefficient++) { // Increment the coefficient till user defined value
            e +=  1.0/factorial(coefficient); // Calculation of e
        }

        printf("Estimated value of e is : %f\n",e); // Prinout of e
    }
    return 0;
}