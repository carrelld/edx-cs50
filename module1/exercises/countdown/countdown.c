#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int start;
    do
    {
        printf("Count down from: ");
        start = GetInt();
    } while(start < 0);
    
    for( ; start > 0; start--)
    {
        printf("%d...\n", start);
    }
    
    printf("BLAST OFF!\n");
}