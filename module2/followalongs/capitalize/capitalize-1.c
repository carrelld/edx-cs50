 /**
  * This is a continuation of the last program and you should copy capitalize-0.c so you do not have to 
  * write the whole program. Use the command below, open up capitalize-1.c and watch the video
  * to complete the task. 
  * Make sure you are in this Folder: ~/workspace/module2/followalongs/capitalize
  * 
  *      cp capitalize-0.c capitalize-1.c
  *
  */
  
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    printf("Give me a string please: ");
    string s = GetString();
    
    if (s != NULL)
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (islower(s[i]))
            {
                printf("%c", toupper(s[i]));
            }
            else
            {
                printf("%c", s[i]);
            }
        }
    }
    printf("\n");
}