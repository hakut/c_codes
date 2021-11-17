/**
 * @file task_1.c
 * @author Mehmet Samet HAKUT (msamet.hakut@gmail.com)
 * @brief This program calculates the weekly payment of various workers
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

/**
 * @brief Definitions of constants
 * 
 */
#define WEEKS_PER_MONTH 4
#define OVER_TIME_MULTIPLIER 1.5
#define COMMISSION_PAYMENT_PERCENTAGE 0.057
#define COMMISSION_BASE 250
#define HOURS_REQUIRED 40

/**
 * @brief Prints the program menu
 * 
 */
void menu()
{
    puts("Welcome to weekly pay calculator!");
    puts("1. Manager");
    puts("2. Hourly worker");
    puts("3. Commission worker");
    puts("4. Piece worker");
    puts("Please enter one of the employee codes from above (-1 to exit) : ");
}

/**
 * @brief Calculates managers' weekly payment
 * 
 * @param salary salary of manager
 * @return double 
 */
double manager_weekly_pay_calculate(double salary)
{
    printf("Enter salary for manager : ");
    scanf("%lf",&salary);
    return salary / WEEKS_PER_MONTH;
}

/**
 * @brief Calculates hourly workers' weekly payment
 * 
 * @param salary hourly payment of worker
 * @return double 
 */
double hourly_worker_pay_calculate(double salary)
{
    double hours;
    printf("Enter hourly pay : ");
    scanf("%lf",&salary);
    printf("Enter how many hours worked : ");
    scanf("%lf",&hours);
    if (hours <= HOURS_REQUIRED) {
        return (salary*hours);
    }
    else {
        return (HOURS_REQUIRED * salary + (hours - HOURS_REQUIRED) * salary * OVER_TIME_MULTIPLIER);
    }
}

/**
 * @brief Calculates commission workers' weekly payment
 * 
 * @param sales total sale of commission worker
 * @return double 
 */
double commission_worker_pay_calculate(double sales)
{
    printf("Enter how much sale made : ");
    scanf("%lf",&sales);
    return (COMMISSION_BASE + sales * COMMISSION_PAYMENT_PERCENTAGE);
}

/**
 * @brief Calculates piece workers' weekly payment
 * 
 * @param pay_per_piece payment per piece that is made
 * @return double 
 */
double piece_worker_pay_calculate(double pay_per_piece)
{
    double pieces;
    printf("How much does worker paid per piece : ");
    scanf("%lf",&pay_per_piece);
    printf("Enter how many pieces made : ");
    scanf("%lf",&pieces);
    return (pieces * pay_per_piece);

}

/**
 * @brief Prints out calculation result
 * 
 * @param total_payment Total payment that will be made
 * @param total_managers Total manager number
 * @param total_hourly_workers Total hourly worker number
 * @param total_commission_workers Total commission worker number
 * @param total_piece_workers Total piece worker number
 */
void final_printout(double total_payment, int total_managers, int total_hourly_workers, int total_commission_workers, int total_piece_workers)
{
    printf("Total number of managers : %d\n", total_managers);
    printf("Total number of hourly workers : %d\n", total_hourly_workers);
    printf("Total number of commission workers : %d\n", total_commission_workers);
    printf("Total number of piece workers : %d\n", total_piece_workers);
    printf("Total payment to all workers : %lf\n",total_payment);
}

/**
 * @brief Main function. No surprise here...
 * 
 * @return int 
 */
int main()
{
    int employee_code, total_managers = 0, total_hourly_workers = 0, total_commission_workers = 0, total_piece_workers = 0;
    double salary, payment = 0, total_payment = 0;
    while (employee_code != -1) {   //  Until the user enters -1 this loop goes on. Which basically prints the menu and gets an input.
        menu();
        scanf("%d",&employee_code);
        fflush(stdin);
        switch (employee_code)  //  Depending on the input calls a function which will calculate the payment for a specific employee type and adds this to total payment.
        {                        //  Also increases the employee type number which will be printed out later.
        case 1:
            total_managers++;
            payment = manager_weekly_pay_calculate(salary);
            total_payment += payment;
            break;

        case 2:
            total_hourly_workers++;
            payment = hourly_worker_pay_calculate(salary);
            total_payment += payment;
            break;

        case 3:
            total_commission_workers++;
            payment = commission_worker_pay_calculate(salary);
            total_payment += payment;
            break;

        case 4:
            total_piece_workers++;
            payment = piece_worker_pay_calculate(salary);
            total_payment += payment;
            break;
        
        }
    }
    final_printout(total_payment, total_managers, total_hourly_workers, total_commission_workers, total_piece_workers); // Calls the holy function to printout the final result.

}