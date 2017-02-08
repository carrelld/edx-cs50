/**
 * write a program that converts the number of minutes in a shower to 
 * number of 16oz bottles of water.
 * 
 * 192 oz per minute of shower
 * 16 oz per bottle of water
 *
 * Don't worry about negative number checking or overflow
 */
 
#include <stdio.h>
#include <cs50.h>

const int oz_per_minute_shower = 192;
const int oz_bottle_water = 16;

int main(void)
{
    printf("minutes: ");
    int minutes_shower = GetInt();
    
    int bottles = minutes_shower * oz_per_minute_shower / oz_bottle_water;
    printf("bottles: %i\n", bottles);
}