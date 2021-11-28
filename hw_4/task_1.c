/**
 * @file task_1.c
 * @author Mehmet Samet HAKUT (msamet.hakut@protonmail.com)
 * @brief This program calculates and prints all prime numbers in range 1 - 999
 * Then prints total prime numbers for every 100 number
 * Then prints total prime numbers in range 1 - 999
 * @version 0.1
 * @date 2021-11-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

#define ARRAY_LENGTH 1000   //  Definition of array length

/**
 * @brief main function and only function
 * 
 * @return int 
 */
int main( void )
{
    int set[ARRAY_LENGTH],i,j,counter = 0;  //  Definition of variables

    /*  Initialization of array set */
    for( i = 0 ; i < ARRAY_LENGTH ; i++ ){
        set[i] = 1;
    }

    set[0] = set[1] = 0;    //  We know that 0 and 1 are not prime so we set them to 0
    printf("\n\n"); //  For better view
    /*  Starting from subscript 2 we do remainder operation.
        Also check the number we are checking is not the same with the divider.
        If remainder is 0 then the number is not prime since prime number can be divided by 1 or itself.
    */
    for( i = 2 ; i <= ARRAY_LENGTH ; i ++){
        for( j = 2 ; j < i ; j++ ){
            if( i % j == 0 && i != j ){
                set[i] = 0;
            }
        }
    }

    /*  Then we print all the prime numbers */
    for( i = 0 ; i < ARRAY_LENGTH ; i++ ){
        if( set[i] == 1 ){
            counter++;
            printf("%3d is prime\t",i);
        }
        /*  This fits my screen perfectly but I'm not sure if it will to yours. 
            Maybe you have some space left on the right maybe it will f* up your console.
            I hope it works perfect on your screen, too.
        */
        if(counter == 13){
            counter = 0;
            puts("");
        }
    }
    counter = 0;
    printf("\n\n"); //  For better view

    j = 1 ; //  j is used here for determine the range
    /*  We print the total prime numbers for every 100 number */
    for ( i = 1 ; i <= ARRAY_LENGTH ; i++ ){
        if( i % 100 == 0){
            printf("Total prime numbers between %d and %d is %d\n", j, i, counter);
            j = i;
            counter = 0;
        }
        if( set[i] == 1){
            counter++;
        }
    }

    /*  Then we calculate all prime numbers in range 1 - 999 */
    for( i = 0 ; i < ARRAY_LENGTH ; i++ ){
        if( set[i] == 1 ){
            counter++;
        }
    }
    puts("");   //  For better view
    printf("Total prime numbers is %d\n\n\n", counter);  // Printing total prime numbers

    return 0;
}