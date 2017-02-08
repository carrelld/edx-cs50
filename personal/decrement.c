#include <stdio.h>

int main(void)
{
    printf("while: decrement after\n");
    int i = 3;
    while (i-- > 0)
    {
        printf("%d\n", i);
    }
    printf("value after loop: %d\n", i);
    
    printf("while: decrement before\n");
    int j = 3;
    while (--j > 0)
    {
        printf("%d\n", j);
    }
    printf("value after loop: %d\n", j);
    
    printf("for loop\n");
    int k = 3;
    for ( ; k > 0; k--)
    {
        printf("%d\n", k);
    }
    printf("value after loop: %d\n", k);
}