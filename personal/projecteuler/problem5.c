/* Smallest multiple
Problem 5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>

int main(void)
{
    int prod = 0;
    do
    {
        prod += 20 * 19; // n and n-1 should have no common prime factors
        for(int i = 1; i < 19; ++i)
        {
            if(prod % i > 0)
            {
                break;
            }
            else if (i == 18)
            {
                printf("%i\n", prod);
                return 0;
            }
        }
    } while(1);
}