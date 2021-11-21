/**
 * @file task_3.c
 * @author Mehmet Samet HAKUT (msamet.hakut@gmail.com)
 * @brief This program calculates gcd of two integer inputs
 * @version 0.1
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
/**
 * @brief calculates gcd of two integers
 * 
 * @param x integer number 1
 * @param y integer number 2
 * @return int gcd of two integers
 */
int gcd(int x, int y)
{
    if( y == 0 ) {  //  If y == 0 returns x as gcd as explained in the hw
        return x;
    }
    else {  // Otherwise sends y as x and x%y as y to the function again
        gcd(y, x % y);
    }
}

void main()
{
    int x,y;
    while( 1 ) {
        printf("Enter two number which are x and y to find gcd of these numbers ( Enter -1 for either one to exit ) : ");
        scanf("%d %d", &x, &y); //  Gets input
        fflush(stdin);
        if( x == -1 || y == -1 )    //  If either of the inputs is -1 exit program
            break;
        printf("GCD of numbers %d and %d is %d\n", x, y, gcd(x,y)); //  Else print the result
    }
}