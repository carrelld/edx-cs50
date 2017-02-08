#include <cs50.h>
#include <stdio.h>

void SwapCycle(int* x, int* y, int* z);

int main(void)
{
    int x = 1;
    int y = 2;
    int z = 3;

    printf("Before swap:\n");
    printf("x is %i \ny is %i \nz is %i\n", x, y, z);

    printf("Swapping...\n");

    SwapCycle(&x, &y, &z);

    printf("After swap:\n");
    printf("x is %i \ny is %i \nz is %i\n", x, y, z);
}

void SwapCycle(int* x, int* y, int* z)
{
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}