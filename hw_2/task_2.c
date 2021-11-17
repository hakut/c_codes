/**
 * @file task_2.c
 * @author Mehmet Samet HAKUT (msamet.hakut@gmail.com)
 * @brief This program prints a calendar between years 1994 and 1999
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>

/**
 * @brief Prints the calendar of the year that it gets
 * 
 * @param year Year that we want to print
 * @param leap_year Whether that year is leap year or not
 */
void print_calender(int year, int leap_year);

/**
 * @brief Main function. Nothing fancy...
 * 
 */
void main()
{
    int year;
    int leap_year;

    while (1) { // Loop forever
    do {
        printf("Enter a year between 1994 and 1999 ( -1 to exit ): ");
        scanf("%d",&year);
    }
    while ( (year < 1994 || year > 1999) && year != -1); // Program gets year input from user until it gets number between 1994 and 1999 or -1

    if ( year == -1 )   // If -1 exit program
        break;
        
    if ( (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) ) {  //  Leap year algorithm. If 1 leap it is a leap year if not it's not
        leap_year = 1;
    }
    else {
        leap_year = 0;
    }
    print_calender(year,leap_year); //  Here we summon the function. Oh, all mighty function! Come and give us the calendar of the year!!!
    }
 }

 void print_calender(int year, int leap_year)
 {
     int position, total_days; // Declaration of starting day position of month and total number of days in a month
     switch (year) {    // Switch case method to determine starting day of the January
     case 1994:
        position = 6;
        break;
     case 1995:
        position = 7;
        break;

    case 1996:
        position = 1;
        break;
    
    case 1997:
        position = 2;
        break;
    
    case 1998:
        position = 3;
        break;

    case 1999:
        position = 4;
        break;
    }

    for ( int month = 1 ; month < 12 ; month++ ) {  //  A for loop of months in the year that has gotten
        switch (month)  //  A switch case for determining every months day number and printing the month name
        {
        case 1:
            puts("");
            puts("\t\tJanuary\t\t");
            total_days = 31;
            break;

        case 2:
            puts("");
            puts("\t\tFebruary\t\t");
            if ( leap_year == 1) {  //  For leap years february has 29 days other days it has 28
                total_days = 29;
            }
            else {
                total_days = 28;
            }
            break;
            
        case 3:
            puts("");
            puts("\t\tMarch\t\t");
            total_days = 31;
            break;
            
        case 4:
            puts("");
            puts("\t\tApril\t\t");
            total_days = 30;
            break;
            
        case 5:
            puts("");
            puts("\t\tMay\t\t");
            total_days = 31;
            break;
            
        case 6:
            puts("");
            puts("\t\tJune\t\t");
            total_days = 30;
            break;
            
        case 7:
            puts("");
            puts("\t\tJuly\t\t");
            total_days = 31;
            break;
            
        case 8:
            puts("");
            puts("\t\tAugust\t\t");
            total_days = 31;
            break;
            
        case 9:
            puts("");
            puts("\t\tSeptember\t\t");
            total_days = 30;
            break;
            
        case 10:
            puts("");
            puts("\t\tOctober\t\t");
            total_days = 31;
            break;
            
        case 11:
            puts("");
            puts("\t\tNovember\t\t");
            total_days = 30;
            break;
            
        case 12:
            puts("");
            puts("\t\tDecember\t\t");
            total_days = 31;
            break;
        }

        puts("Mon\tTue\tWed\tThu\tFri\tSat\tSun");  //  Days written
        for ( int pos = 1 ; pos < position ; pos++ ) { //  Until starting position we print spaces
            printf("   \t");
        }
        for ( int day = 1 ; day <= total_days ; day++ ) {   //  Starting from day 1 to day total_days we print the day number
            printf("%d\t", day);
            if ( position == 7 ) { //  If position is end of the week we assing 1 to position and print new line.
                printf("\n");
                position = 1;
            }
            else {  // Otherwise we increase the position
                position++;
            }
        }
        puts("");
    }




 }