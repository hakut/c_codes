/**
 * This program is written for estimation of number e^x
 * 
**/
#include <stdio.h>

/**
 * @brief This function calculates the factorial of passed parameter
 * 
 * @param value used to take factorial
 * @return int 
 */
int factorial(int value)
{
    if (value == 0) {
        return 1;
    }

    else {
        return(value * factorial(value - 1));
    }
}

/**
 * @brief This function returns value raised to the power of pow.
 * 
 * 
 * @param value base value
 * @param pow power value
 * @return float 
 */
float power(int value, int pow)
{
    if (pow == 0) { // If power is 0 return 1
        return 1;
    }

    /*  For negative powers use recursive function and negate power.
        Also, take the multiplicative inverse of calculated value.
    */
    else if (pow < 0) {
        return 1/power(value, -pow);
    }

    // Same thing as else if but this time don't take inverse of value
    else {
        return(value * power(value, pow -1));  
    }
}

/**
 * @brief Main function gets the input from the user and use this input to
 * determine the precision of calculation and also the coefficient. 
 * Also we use 1 as e init value and we summate the e with coefficient over 
 * factorial of increasing counter, which its final value is determined by user input.
 * So that we get estimated e value.
 * 
 * @return int 
 */
int main(){
    while (1) {
        float e = 1;
        int coefficient = 1, precision, pow, is_type_correct;
        start:
        printf("Please enter a number to determine the precition of formula (-1 to exit): ");
        is_type_correct = scanf("%d",&precision); // Gets precision value
        fflush(stdin);
        
        if (is_type_correct == 0) { // If not integer go to start
            goto start;
        }

        // According to my try and error best precision value is 12-13
        if(precision == -1) { // If input is -1 exit program
            break;
        }

        start2:
        printf("Please enter the power of e : ");
        is_type_correct = scanf("%d",&pow); // Gets the coefficient (Also can be defined as power of e)
        fflush(stdin);

        if (is_type_correct == 0) { // If not integer go to start
            goto start2;
        }

        for ( ; coefficient <= precision ; coefficient++){
            e += (float)power(pow,coefficient)/factorial(coefficient); // Calculation of e^x value
        }

        printf("Estimated e^%d is : %f\n",pow,e); // Printout of estimation
    }
    return 0;
}