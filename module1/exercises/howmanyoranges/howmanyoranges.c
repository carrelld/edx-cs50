#include <stdio.h>
#include <math.h>
#include <cs50.h>

const int slices_per_orange = 8; //slices per orange

int main(void)
{
    printf("How many orange slices do you want to eat? ");
    int slices_wanted = GetInt();
    
    float num_oranges = ceil((float)slices_wanted / (float)slices_per_orange);
    printf("You should buy %.1f oranges!\n", num_oranges);
}