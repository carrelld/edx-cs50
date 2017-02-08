/**
 * write a program that draws a pyramid of #'s with user specified height climbing to the right
 * restrict input to between 0 and 23
 * each step is 1-wide except for the last one which is 2-wide
 * align the pyramid so that the bottom left is in column 1 in the terminal
 */
 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /* user input */
    int h;
    do
    {
        printf("Height: ");
        h = GetInt();
    } while(h < 0 || h > 23);
    
    /* generating the pyramid */
    for( int i = h; i > 0; i--)
    {
        int spaces = i - 1;
        for( int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        int hash = h + 1 - spaces;
        for( int j = 0; j < hash; j++)
        {
            printf("#");
        }    
        printf("\n");
    }
}
