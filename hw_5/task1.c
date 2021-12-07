/**
 * @file task1.c
 * @author Mehmet Samet HAKUT (msamet.hakut@protonmail.com)
 * @brief This program creates a simulation of hare and tortoise race in a mountain with 70 steps
 * At each tick of the clock both hare and tortoise moves. This move is random and depending on the chance of movement
 * they can slip, move forward or stay where they are. If they both in the same step tortoise bites hare and an OUCH is printed
 * on the step. After one of them reaches the finish line or pass that line. Race ends and winner declared. If it's a tie.
 * The announcement says so.
 * @version 0.1
 * @date 2021-12-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Hare movement function. It generates an integer from 1 to 10
 * Depending on the integer hare does it's move.
 * 
 * @param H Points the position of hare
 */
void move_hare(int *H);

/**
 * @brief Tortoise movement function. It generates an integer from 1 to 10
 * Depending on the integer tortoise does it's move.
 * 
 * @param T Points the position of tortoise
 */
void move_tortoise(int *T);

int main( void )
{
    int *H, *T, i, tick_tock;  //  Definition of hare, tortoise pointers and also an integer for for loop and a timer
    char input[2];  //  Char array for determination of whether there is gonna be a revenge match or not.
    H = (int*)malloc(1);    //  Memory allocation for hare pointer
    T = (int*)malloc(1);    //  Memory allocation for tortoise pointer
    while(strcmp("no",input)){  //  Compare string with 'no' if the input is no returns 0 and exits loop
        *H = 1; //  Initial positions for hare and tortoise
        *T = 1;
        tick_tock = 0;
        puts("BANG !!!");   //  Race start
        puts("AND THEY'RE OFF !!!");
        do{ //  This loop lasts until the race reaches an end.
            move_hare(H);   //  Hare does its move
            move_tortoise(T);   //  Tortoise does its move
            for( i = 1 ; i <= 70 ; i++ ){   //  At each loop we print the steps
                if( i == *H && i == *T){    //  If both hare and tortoise at the same step print OUCH
                    printf("OUCH!!!");
                }
                else if( i == *H){  //  If the position matches the hare position print H
                    printf("H");
                }
                else if( i == *T ){ //  If the position matches the tortoise position print T
                    printf("T");
                }
                else{
                    printf("_");    //  Otherwise print _ as step
                }
            }
        puts("");// After we complete every steps for 70 steps new line
        tick_tock++;
        }while ( *H < 70 && *T < 70);   //  If either hare or tortoise passes the finish line end the loop
        printf("Time elapsed : %d sec\n", tick_tock);
        if( *H >= 70 && *T < 70){   //  If hare passes the finish line and tortoise not print hare wins
            puts("Hare wins. Yuch");
        }
        else if( *T >= 70 && *H < 70){  //  If tortoise passes the finish line and hare not print tortoise wins
            puts("TORTOISE WINS!!! YAY!!!");
        }
        else{   //  Otherwise, print its a tie
            puts("It's a tie");
        }
        printf("Do you want another race? (Enter 'go' or 'no')");   //  Ask user if he/she wants a rematch
        scanf("%s",&input);
        fflush(stdin);
        puts("");   //  New line for new match
    }
        
}

void move_hare(int *H)
{
    
    int i = 1 + rand() % 10;    //  Create a random integer from 1 to 10
    if( i >= 1 && i <= 2){  //  If the integer between 1 and 2 hare does nothing
    }
    else if( i >=3 && i <= 4){  //  If the integer between 3 and 4 hare jumps forward 9 steps
        *H += 9;
    }
    else if( i == 5 ){
        *H -= 12;
    }
    else if( i >= 6 && i <= 8 ){
        *H += 1;
    }
    else if( i >= 9 && i <= 10){
        *H -= 2;
    }

    if( *H < 1 ){   //  If hare positon less than 1 position it to 1
        *H = 1;
    }

}

void move_tortoise(int *T)
{
    
    int i = 1 + rand() % 10;    //  So for tortoise create another random int between 1 to 10
    if( i >= 1 && i <= 5){  //  Do the things according to table
        *T += 3;
    }
    else if( i >=6 && i <= 7){
        *T -= 6;
    }
    else if( i >= 8 && i <= 10 ){
        *T += 1;
    }

    if( *T < 1 ){   //  If tortoise positon less than 1 position it to 1
        *T = 1;
    }

}