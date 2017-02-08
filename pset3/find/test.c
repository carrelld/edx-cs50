#include "helpers.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int searchfor = 0;
    int a[] = {101, 6, 7, 3, 9, 4, -50, 0, 99};
    int n = sizeof(a)/sizeof(a[0]);
    
    for (int i = 0; i < n; i++)
    {
        printf("%i, ", a[i]);
    }
    printf("\n");
    
    sort(a, n);
    
    for (int i = 0; i < n; i++)
    {
        printf("%i, ", a[i]);
    }
    printf("\n");
    
    bool found = search(searchfor, a, n);
    printf("%i\n", found);
}