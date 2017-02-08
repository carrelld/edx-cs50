/**
 * Write a program that first asks the user how much change is owed
 * then spits out the minimum number of coins with which said change can be made
 * 
 * coins available: quarters, dimes nickels and pennies
 * 
 */
 
#include <cs50.h>
#include <stdio.h>
#include <math.h>

const int sizeof_coins_value = 4;
const int coins_value[] = {25, 10, 5, 1};

int main(void)
{
    /* get positive float value */
    float change;
    do
    {
        printf("O hai! How much change is owed? ");
        change = GetFloat();
    } while(change < 0);
    
    /* convert change to int number of pennies */
    int change_pennies = (int) round(100 * change);
    
    /* count the number of coins by iterating through available coins */
    int num_coins = 0;
    for (int i = 0; i < sizeof_coins_value; i++)
    {
        num_coins += change_pennies / coins_value[i];
        change_pennies %= coins_value[i];
    }
    
    /* print output */
    printf("%i\n", num_coins);
}