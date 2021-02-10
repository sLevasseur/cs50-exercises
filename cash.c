#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    float cash;
    do 
    {
     cash = get_float("change owed : ");
    }while (cash < 0.0);
    
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    int counterOfCoins = 0;
    int cashCounter = 0;
    
    int rounded = round(cash * 100);
    do {
    if (cashCounter+quarter <= rounded)
    {
        cashCounter+=quarter;
        counterOfCoins++;
    } else if (cashCounter+dime <= rounded)
    {
            cashCounter += dime;
            counterOfCoins++;
    } else if (cashCounter+nickel <= rounded)
    {
        cashCounter+=nickel;
        counterOfCoins++;
    }
    else
    {
        cashCounter+=penny;
        counterOfCoins++;
    }
    } while (cashCounter < rounded);
    
    printf("%i\n", counterOfCoins);
    
    
}