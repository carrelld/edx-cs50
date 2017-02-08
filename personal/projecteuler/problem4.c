/*Largest palindrome product
Problem 4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>

int reverse(int a);
int is_palindrome(int a);

int main(void)
{
    int ubound = 999 * 999;
    int lbound = 100 * 100;
    
    for( ; ; )
    {
        for( ; ubound > lbound; --ubound)
        {
            if(is_palindrome(ubound) == 1)
            {
                //printf("%i\n", ubound);
                for(int i = 999; i > 100; --i)
                {
                    if(ubound % i == 0 && ubound / i > 100 && ubound / i < 999)
                    {
                        printf("%i and %i is %i\n", i, ubound / i, ubound);
                        return 0;
                    }
                }
            }
        }
    }
}

int reverse(int a)
{
    int rem = 0;
    int rev = 0;
    while(a != 0)
    {
        rem = a % 10;
        a = a / 10;
        rev = rev * 10 + rem;
    }
    return rev;
}

int is_palindrome(int a)
{
    return a == reverse(a) ? 1 : 0;
}