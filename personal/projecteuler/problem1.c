/* Multiples of 3 and 5
Problem 1
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 
3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>

int main(void)
{
    int multiple = 1;
    int sum = 0;
    int mthree = 0;
    int mfive = 0;
    
    while(mthree < 1000)
    {
        mthree = multiple * 3;
        mfive = multiple * 5;
        sum += mthree;
        if((mfive < 1000) && (mfive % 3 != 0))
        {
            sum += mfive;
        }
        ++multiple;
    }
    printf("sum = %i", sum);
}