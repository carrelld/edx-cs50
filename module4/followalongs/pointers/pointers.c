/**
* Filename: pointers.c
* Save in Folder: ~/workspace/module4/followalongs/pointers
* 
* Include the cs50 library
* Include the stdio library
* Include the string library
*
* Add main method
*
*    Declare a pointer called s of type char and assign the user input to it
*    Hint: <type>* <variable name> = GetString();
*    If (s == NULL)
*        return 1;
*
* 
* You will find instructions to complete this task in the video. 
* You will be modifying this code as you go along.
*
*/

#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    char* s = GetString();
    if (s == NULL)
    {
        return 1;
    }
    
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c\n", *(s + i));
    }
}