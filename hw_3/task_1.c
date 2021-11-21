/**
 * @file task_1.c
 * @author Mehmet Samet HAKUT (msamet.hakut@gmail.com)
 * @brief This program determines a random char and wants you to guess it. Depending on your guess
 * it gives you random output from 3 strings. If the choice is correct output is standart. If wrong
 * it gives you one of the two senteces. This goes on until you guess right. If so, it prints out the
 * your guess is right string and depending on your guess counter prints one of the two strings previously determined by the programmer
 * @version 0.1
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h> //  Stdlib library for rand() function

/**
 * @brief Standart program menu
 * 
 */
void starting_menu();
/**
 * @brief function that does all the work like determining if the guess correct
 * and printing out everything that program can print
 * 
 * @param real_char random char stored by program to be guessed
 * @return int return value to exit program or continue the progress
 */
int is_guess_correct(char real_char);

void main()
{
    char determined_char;   // Computer determined char
    int ret;    // Return value of the function
    while ( ret == 0 ) {    //  Loop goes on as long as return value is 0
        determined_char = 'A' + (rand() % 26);  // Determine a random character
        printf("%c\n",determined_char); //  This one line is for testing if the counter works as designed
        starting_menu();    // Program menu
        ret = is_guess_correct(determined_char);    //  function call and return value assignment
    }
}

void starting_menu()
{   //  Nothing fancy here just some print outs
    puts("I have selected a character between A and Z");
    puts("Try to guess the character selected by me!");
    puts("What is your guess? ( Enter 'x' to exit )");
}

int is_guess_correct(char real_char)
{   //  This is where things get interesting
    char guessed_char;
    int random, counter = 0;
    scanf("%c", &guessed_char); //  Input of the guess
    fflush(stdin);  //  Clean cache is everything
    while ( real_char != guessed_char ) {   //  If input is not the same as determined_char go on ( Here we can do this because characters also have a number equivalent according to ascii table )
        if (guessed_char == 'x') {  // If we enter x as char exit program
            return -1;  // Return other than 0 so that while loop breaks
        }
        counter++;  //  Increase the guess counter
        random = rand()%2;  //  Guess is wrong, print one of the two predetermined sentences
        switch (random) {
        case 0:
            puts("Way ahead! Please try again.");
            break;
        case 1:
            puts("Way behind! Please try again.");
            break;
        }
        scanf("%c", &guessed_char); //  Guess again ( insert <do it again meme> )
        fflush(stdin);  //  Same old same old
    }
    puts("Great! Your guess is right!");    //  If guess is right. Compliment the user.
    if (counter > 5) {  //  If the user couldn't guess in 5 tries encourage him/her.
        puts("You should be able to do better!");
    }
    else {  //  If the user cheats say something
        puts("I guess you know the secret!");
    }
    return 0;   // Return 0 for program to keep going
}