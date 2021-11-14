/**
 * This program is written for calculating factorial of given integer
 * 
**/
#include <stdio.h>

/**
 * @brief This function takes factorial of the parameter that passed...
 * 
 * @param value 
 * @return int 
 */
int factorial(int value){
    if(value == 0){
        return 1;
    }
    
    return(value * factorial(value - 1));
}

/**
 * @brief Main function takes an argument from the user and passes that argument
 * to the factorial function and prints out the result until it gets -1 as entry.
 * In that case it exits program
 * 
 * @return int 
 */
int main(){
    unsigned int fac_entry, is_type_correct;

    while (1) { // Infinite loop till it gets -1
        start:
        printf("Enter a number to take its factorial (-1 to exit) : ");
        is_type_correct = scanf("%d",&fac_entry); // Ask user input for factorial calculation
        fflush(stdin);

        if (is_type_correct == 0) { // If not integer ask again
            goto start;
        }

        if (fac_entry == -1) { // Entry is -1 so exit the program
            break;
        }

        printf("Factorial of %d is : %d\n",fac_entry, factorial(fac_entry)); // Calls the function and prints out the result
    }
    return 0;
}