#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        printf("Give me an even integer please: ");
        n = GetInt();
    } while(n % 2 != 0);
    
    printf("Thanks! I got what I wanted\n");
}