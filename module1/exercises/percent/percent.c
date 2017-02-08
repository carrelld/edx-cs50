/**
 * purpose: program asking user for two floats
 * then compute the ratio between them
 * output as percentage
 */
 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("float please: ");
    float x = GetFloat();
    
    printf("float please: ");
    float y = GetFloat();
    
    printf("%f percent\n", x / y * 100);
}