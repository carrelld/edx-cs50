 /**
  * This is a continuation of the last program and you should copy string-0.c so you do not have to 
  * write the whole program. Use the command below, open up string-1.c and watch the video
  * to complete the task. 
  * Make sure you are in this Folder: ~/workspace/module2/followalongs/string
  * 
  *      cp string-0.c string-1.c
  *
  */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = GetString();
    
    if (s != NULL)
    {
        for (int i = 0; i < strlen(s); i++)
        {
            printf("%c\n", s[i]);
        }
    }

}