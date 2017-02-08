/**
* This is a continuation of the last program and you should copy compare-0.c file so you do not have to 
* write the whole program. Use the command below, open up compare-1.c and watch the video
* to complete the task.  
* Make sure you are in this Folder: ~/workspace/module4/followalongs/compare
*
*      cp compare-0.c compare-1.c
*
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Say something: ");
    char* s = GetString();
    
    printf("Say something: ");
    char* t = GetString();

    if (s != NULL && t != NULL)
    {
        if (strcmp(s, t) == 0)
        {
            printf("You typed the same thing!\n");
        }
        else
        {
            printf("You typed different things!\n");
        }
    }
}