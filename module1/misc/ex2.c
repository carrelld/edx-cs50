#include <stdio.h>
#include <cs50.h>

/** program to determine the number of days, hours and minutes when given some minutes as input
 * no selection allowed!
 */
 
int main(void)
{
    printf("How many minutes? ");
    int min = GetInt();
    int day = min / (60 * 24);
    min -= day * (60 * 24);
    int hour = min / 60;
    min -= hour * 60;
    
    printf("The value you gave is %d days, %d hours, and %d minutes.\n", day, hour, min);
}