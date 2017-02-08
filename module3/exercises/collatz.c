#include <cs50.h>
#include <stdio.h>

int collatz(int m);

int main(void)
{
    int n;
    do
    {
        printf("Positive integer please to Collatz: ");
        n = GetInt();
    }
    while (n < 1);

    int answer = collatz(n);
    printf("collatz steps = %i\n", answer);
}

int collatz(int m)
{
    if (m == 1)
    {
        return 0;
    }
    else if (m % 2 == 0)
    {
        return 1 + collatz(m / 2);
    }
    else if (m % 2 == 1)
    {
        return 1 + collatz(3 * m + 1);
    }
    else
    {
        return -1;
    }
}