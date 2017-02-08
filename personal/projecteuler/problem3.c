/* Largest prime factor
Problem 3
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <stdio.h>

int is_prime(int x);

int main(void)
{
    long int num = 60515748231; 

    printf("%ld\n", num);
    for(long int i = 2; i < num / i; i = i + 1)
    {
        if(num % i == 0)
        {
            num /= i;
            printf("%ld, %ld\n", i, num);
            i -= 1;
        }
    }
}