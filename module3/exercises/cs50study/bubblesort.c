/*
step through array swapping ajacent pairs if out of order
*/

#include <stdio.h>

#define SIZE 8

void sort(int array[], int size)
{
    int swaps;
    do
    {
        swaps = 0;
        for (int i = 1; i < size; i++)
        {
            if(array[i] < array[i - 1])
            {
                int temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
                swaps += 1;
            }
        }
    }
    while (swaps > 0);
}

int main(void)
{
    int numbers[SIZE] = { 4, 15, 16, 50, 8, 23, 42, 108 };
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    sort(numbers, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}