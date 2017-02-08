#include <stdio.h>

int main(void)
{
    long long unsigned int x = 0;
    long long unsigned int y = 1;
    
    for(int i = 0; i < 50; ++i)
    {
        long long unsigned int temp = x + y;
        printf("%llu, ", x);
        x = y;
        y = temp;
    }
    printf("\n");
}