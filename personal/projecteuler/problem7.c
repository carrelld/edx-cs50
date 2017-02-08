/* 10001st prime
Problem 7
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that 
the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <stdio.h>

int is_prime(int n);

int main(void)
{
    int p_count = 2, p = 3; //p_count 2 for the prime "2" and "3"
    while(p_count < 10001)
    {
        p += 2;
        p_count += is_prime(p) == 1 ? 1 : 0;
    }
    printf("%i is the 10001st prime\n", p);
}

int is_prime(int n)
{
    if(n % 2 == 0)
        return 0;
    for(int i = 3; i * i <= n; i += 2)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}