/**
 * This program is written for decimal conversion of a binary input
 * 
**/
#include <stdio.h>

int main(){
    /* Initialization of required variables such as binary number input decimal number output
    endian and counter for calculation of decimal number and type checker for controlling 
    char input. I didn't implement if entry is other than binary to keep it simple
    */
    unsigned int is_type_correct, bin_num = 0, endian, dec_num, counter = 0;
    while (1) {
        dec_num = 0,counter = 0;

        start:
        printf("Enter a binary number (-1 to exit): ");
        is_type_correct = scanf("%d", &bin_num); // If char entered scanf returns zero
        fflush(stdin); // Flushes buffer for next while loop so that we can enter another value

        if (bin_num == -1) { // If entry is -1 exit the program
            break;
        }

        if (is_type_correct == 0) { // If type is not int takes a new input until it gets an int
            goto start;
        }

        while (bin_num > 0) { // Loop here for binary number greater than 0 if 0 it won't effect output since the multiplication is 0
            endian = bin_num % 10; // Take the last digit
            bin_num /= 10; // Divide by 10 to remove last digit
            /* Shifting operator is used for multiplication with 2 since shifting 1 bit left is multiplication with 2
            ** So we multiply with 2*counter and counter increases as we move another digit. At first it is 0*/
            endian <<= counter;
            dec_num += endian; // Decimal number is summation of endians
            counter++; // increase counter since we do multiplication by 2*counter
        }

        printf("Decimal number is : %d\n",dec_num); // Print out the decimal number
        
    }
    return 0;
}