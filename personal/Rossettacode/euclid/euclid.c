#include <stdio.h>
#include <cs50.h>

int main(void) {
    printf("First number: ");
    int x = GetInt();
    
    printf("Second number: ");
    int y = GetInt();
    
    int z = 0;
    do {
        z = x % y;
        x = y;
        y = z;
        
    } while(z > 0);
    
    printf("The greatest common divisor is: %d\n", x);
}