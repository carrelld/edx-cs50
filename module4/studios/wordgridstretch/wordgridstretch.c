/**
* Filename: wordgridstretch.c
* Save in Folder: ~/workspace/module4/studios/wordgridstretch
*
* The word grid is back with a vengence!
*
* Just like last week, this studio involves taking some strings from the user, and then printing them back out in a transformed way.
*
* Today, your program will apply a "stretch" factor to the grid of letters, making it larger.
* 
* It is easiest to explain via example. The finished program should behave like this:
* 
* $ ./wordgridstretch goat crab bear
* Your word grid currently looks like this:
* goat
* crab
* bear
* Now I will stretch it out. How much should I stretch by?
* 3
* After stretching by 3, you now have this!
* gggoooaaattt
* gggoooaaattt
* gggoooaaattt
* cccrrraaabbb
* cccrrraaabbb
* cccrrraaabbb
* bbbeeeaaarrr
* bbbeeeaaarrr
* bbbeeeaaarrr
* That's what we mean by "making the grid larger".
* 
* Validation
* 
* Don't forget to validate the user's input. Specifically, you'll want to ensure:
* 
*   1. that the user gave you exactly 3 words as command-line arguments
*   2. that those words are all the same length
*   3. that the user provides a non-negative stretch factor
*  
* Submitting
* 
* You don't have to submit stretchvertical.c and stretchhorizontal.c. You only have to submit wordgridstretch.c.
*/

#include <stdio.h>
#include <string.h>
#include <cs50.h>

void VStretch(char* s, int stretch);
void HStretch(char* s, int stretch);

int main(int argc, char** argv)
{
    // Confirm correct user input
    if (argc != 4)
    {
        return 1;
    }
    int grid_width = strlen(argv[1]);
    for (int i = 2; i < argc; i++)
    {
        if (strlen(argv[i]) != grid_width)
        {
            return 1;
        }
    }
    
    // Interface
    printf("Your word grid currently looks like this:\n");
    for (int i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    
    // Stretch factor
    printf("Now I will stretch it out. How much should I stretch by?\n");
    int stretch_factor = GetInt();
    if (stretch_factor < 1)
    {
        return 1;
    }
    
    // Output
    printf("After stretching by %d, you now have this!\n", stretch_factor);
    for (int i = 1; i < argc; i++)
    {
        VStretch(argv[i], stretch_factor);
    }
    
}

void VStretch(char* s, int stretch)
{
    for (int i = 0; i < stretch; i++)
    {
        HStretch(s, stretch);
    }
}

void HStretch(char* s, int stretch)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        for (int j = 0; j < stretch; j++)
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}