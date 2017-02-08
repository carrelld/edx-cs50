/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"

/**
 * binary search recursive function
 */
int binarysearch(int value, int *a, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (a[mid] == value)
    {
        return true;
    }
    else if (end == start)
    {
        return false;
    }
    else
    {
        if (value > a[mid])
        {
            return binarysearch(value, a, mid + 1, end);
        }
        else
        {
            return binarysearch(value, a, start, mid - 1);
        }
    }
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    return binarysearch(value, values, 0, n - 1) > 0 ? true : false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int swap;
    int temp;
    int loop = 0;
    
    do
    {
        swap = 0;
        loop += 1;
        for (int i = 0; i < n - loop; i++)
        {
            if (values[i] > values[i + 1])
            {
                temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                swap += 1;
            }
        }
    } while(swap != 0);
}

