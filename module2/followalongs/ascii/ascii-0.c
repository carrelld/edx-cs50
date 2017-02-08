/**
  * Filename: ascii-0.c
  * Save in Folder: ~/workspace/module2/followalongs/ascii
  * 
  * Include the stdio library
  * Add main method
  *   Add a for loop using a variable i that is initialized to 65 of type int and a condition of (i < 65 + 26)
  *   (Hint: for ( initialization; condition; updates) { statement(s); } 
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  *
  */
  
#include <stdio.h>

int main(void)
{
    for(int i = 65; i < 65 + 26; ++i)
    {
        printf("%i is %c\n", i, (char) i);
    }
}