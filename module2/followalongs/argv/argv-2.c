/**
  * This is a continuation of the last program and you should copy argv-1.c so you do not have to 
  * write the whole program. Use the command below, open up argv-2.c and watch the video
  * to complete the task. 
  * Make sure you are in this Folder: ~/workspace/module2/followalongs/argv 
  * 
  *      cp argv-1.c argv-2.c
  *
  */
  
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    for (int i = 0; i < argc; i++)
    {
        for (int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            printf("%c\n", argv[i][j]);
        }
        
    }
}