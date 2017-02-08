 /**
  * This is a continuation of the last program and you should copy argv-0.c so you do not have to 
  * write the whole program. Use the command below, open up argv-1.c and watch the video
  * to complete the task. 
  * Make sure you are in this Folder: ~/workspace/module2/followalongs/argv 
  * 
  *      cp argv-0.c argv-1.c
  *
  */
  
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}