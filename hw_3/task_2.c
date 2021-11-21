/**
 * @file task_2.c
 * @author Mehmet Samet HAKUT (msamet.hakut@gmail.com)
 * @brief This program calculates the fibonacci series and prints out the nth number that you want
 * @version 0.1
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
/**
 * @brief returns the nth fibonacci number
 * 
 * @param input variable determines which fibonacci number that you want to learn
 * @return unsigned long long int returns the nth fibonacci number
 */
unsigned long long int fibonacci(unsigned int input)
{
    unsigned long long int first = 0, temp, result = 1; //  first two fibonacci numbers are 0 and 1 hence first and result. temp is for assignment part
    if( input == 0 ) {  //  If input is 0 return 0 since the 0th fibonacci number is 0
        return 0;
    }
    /* 0 1 1 2 3 5 ...
    for 0 result = 0
    for 1 result = 1
    for 2 temp = 0; first = 1; result = 1 + 0 = 1;
    for 3 temp = 1; first = 1; result = 1 + 1 = 2;
    for 4 temp = 1; first = 2; result = 2 + 1 = 3;
    for 5 temp = 2; first = 3; result = 3 + 2 = 5;
    for 6 temp = 3; first = 5; result = 5 + 3 = 8;
    So on and so forth
    */
    for( int i = 2 ; i <= input ; i++) {    // Otherwise, do the following. Note that if input is 1 there is no for loop and returns 1 since result is assigned to 1 already
        temp = first;   //  assign first to temp to store previous value
        first = result; //  Assign result to first again to store the value. This is basically shifting in an array
        result += temp; //  Summate result with temp which is summation of two numbers before result
    }
    return result;  // Return result
}

void main()
{
    unsigned int input;
    do {    //  
        printf("Enter a number n to find nth fibonacci number (-1 to exit) : ");
        scanf("%d",&input); //  Gets input
        if( input == -1 )   //  If -1 exit program
            break;
        printf("%d th fibonacci number is : %llu\n",input,fibonacci(input));    // 300th fibonacci number is largest can be calculated by this program. Because of the restriction of llu
    }
    while( 1 );
}