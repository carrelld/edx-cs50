#include <stdio.h>
#include <cs50.h>

void computearray(int a[], int );

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    computearray(a, 5);
}

void computearray(int a[], int n)
{

    /* smallest */
    int small = a[0];
    for (int i = 1; i < n; i++)
    {
        if(a[i] < small)
            small = a[i];
    }
    printf("Min: %d\n", small);
    
    /* largest */
    int large = a[0];
    for (int i = 1; i < n; i++)
    {
        if(a[i] > large)
            large = a[i];
    }
    printf("Max: %d\n", large);
    
    /* average */
    int avg = a[0];
    for (int i = 1; i < n; i++)
    {
        avg += a[i];
    }
    printf("Average: %f\n", (float) avg / n);
}