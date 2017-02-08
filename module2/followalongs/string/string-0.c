 /**
  * Filename: string-0.c
  * Save in Folder: ~/workspace/module2/followalongs/string
  * 
  * Include the stdio library
  * Include the cs50 library
  * Include the string library
  * Add main method
  *   Declare a variable s of type string and assign the function GetString() to it 
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  *
  */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = GetString();
    
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c\n", s[i]);
    }
}