#include <stdio.h>

#define WEEKS_PER_YEAR 52
#define OVER_TIME_MULTIPLIER 1.5
#define COMMISSION_PAYMENT_PERCENTAGE 0.057
#define COMMISSION_BASE 250

void menu()
{
    puts("Welcome to weekly pay calculator!");
    puts("1. Manager");
    puts("2. Hourly worker");
    puts("3. Commission worker");
    puts("4. Piece worker");
    puts("Please enter one of the employee codes from above : ");
}

double manager_weekly_pay_calculate(double salary){
    return salary / 52;
}

int main()
{
    int employee_code, total_managers = 0, total_hourly_workers = 0, total_commission_workers = 0, total_piece_workers = 0;
    double salary, payment_per_group, total_payment;
    while (1) {
        menu();
        scanf("%d",&employee_code);
        fflush(stdin);
        switch (employee_code)
        {
        case 1:
            
            break;
        case 2:
            break;

        case 3:
            break;

        case 4:
            break;
        
        default:
            break;
        }
        }

}