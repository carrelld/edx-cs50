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

#define WORDS 3

void Print_Mult_String_Array(char** s, int n, int start, int end);
int Stretch_Word(char** s, int n, int factor);

int main(int argc, char** argv)
{
    // Confirm correct user input
    if (argc != WORDS + 1)
    {
        printf("./%s <word1> <word2> <word3>\n", __FILE__);
        return 1;
    }
    int argwidth = strlen(argv[1]);
    for (int i = 2; i < argc; i++)
    {
        if (strlen(argv[i]) != argwidth)
        {
            return 1;
        }
    }
    
    // Interface
    printf("Your word grid currently looks like this:\n");
    Print_Mult_String_Array(argv, 1, 1, argc);
    
    // Stretch factor
    printf("Now I will stretch it out. How much should I stretch by?\n");
    int stretchfactor = GetInt();
    if (stretchfactor < 1)
    {
        return 1;
    }
    
    // Establish new stretched array and assign to original array pointer
    for (int i = 1; i < WORDS + 1; i++)
    {
        Stretch_Word(&argv[i], argwidth, stretchfactor);
    }
    

    // Print said array
    printf("After stretching by %d, you now have this!\n", stretchfactor);
    Print_Mult_String_Array(argv, stretchfactor, 1, argc);
    
}

/* 
 * Modify existing array to be stretched out by copying each letter factor
 * times in a new array and point existing pointer to new stretched array
 */
int Stretch_Word(char** s, int n, int factor)
{
    int copysize = n * factor + 1;
    char* s_new = malloc(copysize * sizeof(char));
    if (s_new == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // map s to s_new in a 1:factor manner
    int next = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < factor; j++)
        {
            *(s_new + next++) = *(*s + i);
        }
    }
    // Add string NULL terminator
    *(s_new + copysize - 1) = '\0';
    
    // Point to newly stretched string
    *s = s_new;
    return 0;
}


/* 
 * Print array of strings with each string on a new line N number of times each
 */
 
void Print_Mult_String_Array(char** sarray, int n, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%s\n", *(sarray + i));
        }
    }
}





