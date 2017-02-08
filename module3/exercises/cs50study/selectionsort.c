#include <stdio.h>

#define SIZE 8

void sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int small = i;
        for (int j = i + 1; j < size; j++)
        {
            if(array[j] < array[small])
            {
                small = j;
            }
        }
        if(small != i)
        {
            int tmp = array[small];
            array[small] = array[i];
            array[i] = tmp;
        }
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