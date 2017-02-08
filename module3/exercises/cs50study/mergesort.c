/*
On input of n elements:
    if n < 2
        return
    else
        sort left half of elements
        sort right half of elements
        merge sorted halves
*/

#include <stdio.h>

#define SIZE 8

int temp[SIZE] = {0};

void merge (int array[], int start_1, int end_1, int start_2, int end_2)
{
    int n = end_2 - start_1;
    int i = start_1;
    int j = start_2;
    int debug = 0;
    for (int k = i; k <= n; k++)
    {
        if(i > end_1)
        {
            temp[k] = array[j++];
        }
        else if (j > end_2)
        {
            temp[k] = array[i++];
        }
        else 
        {
            temp[k] = array[i] < array[j] ? array[i++] : array[j++];
        }
    }
    for (i = start_1; i <= n; i++)
    {
        array[i] = temp[i];
    }
}

void sort (int array[], int start, int end)
{
    if (end > start)
    {
        int middle = (start + end) / 2;

        // sort left half
        sort(array, start, middle);

        // sort right half
        sort(array, middle + 1, end);

        // merge the two halves
        merge(array, start, middle, middle + 1, end);
    }
}

int main(void)
{
    int numbers[SIZE] = { 4, 15, 16, 50, 8, 23, 42, 108};
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    sort(numbers, 0, SIZE - 1);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}