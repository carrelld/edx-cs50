#include <stdio.h>

#define SIZE 8

void sort(int array[], int size)
{

    for (int i = 1; i < size; i++)
    {
        int element = array[i];
        int j = i;
        while (array[j-1] > element && j > 0)
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = element;
    }
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