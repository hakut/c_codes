#include <stdio.h>
#include <stdlib.h>

void move_hare(int *H);
void move_tortoise(int *T);

int main( void )
{
    int *H, *T, i;
    char input[2];
    H = (int*)malloc(1);
    T = (int*)malloc(1);
    while(strcmp("no",input)){
        *H = 1;
        *T = 1;
        puts("BANG !!!");
        puts("AND THEY'RE OFF !!!");
        while ( *H < 70 && *T < 70){
            // printf("%d\n",i);
            move_hare(H);
            // printf("%d\n",i);
            move_tortoise(T);
            for( i = 1 ; i <= 70 ; i++ ){
                if( i == *H && i == *T){
                    printf("OUCH!!!");
                }
                else if( i == *H){
                    printf("H");
                }
                else if( i == *T ){
                    printf("T");
                }
                else{
                    printf("_");
                }
            }
            
        puts("");
        }
        if( *H >= 70 && *T < 70){
            puts("Hare wins. Yuch");
        }
        else if( *T >= 70 && *H < 70){
            puts("TORTOISE WINS!!! YAY!!!");
        }
        else{
            puts("It's a tie");
        }
        printf("Do you want another race? (Enter 'go' or 'no')");
        scanf("%s",&input);
        fflush(stdin);
        puts("");
    }
        
}

void move_hare(int *H)
{
    
    int i = 1 + rand() % 10;
    if( i >= 1 && i <= 2){
    }
    else if( i >=3 && i <= 4){
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

    if( *H < 1 ){
        *H = 1;
    }

}

void move_tortoise(int *T)
{
    
    int i = 1 + rand() % 10;
    if( i >= 1 && i <= 5){
        *T += 3;
    }
    else if( i >=6 && i <= 7){
        *T -= 6;
    }
    else if( i >= 8 && i <= 10 ){
        *T += 1;
    }

    if( *T < 1 ){
        *T = 1;
    }

}