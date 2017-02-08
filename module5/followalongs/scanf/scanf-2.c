 /**
  * This is a continuation of the last program and you should copy scanf-1.c file so you do not have to 
  * write the whole program. Use the command below, open up scanf-2.c and watch the video
  * to complete the task.  
  * Make sure you are in this Folder: ~/workspace/module5/followalongs/scanf
  *
  *      cp scanf-1.c scanf-2.c
  *
  */

#include <stdio.h>

int main(void)
{
    char s[16];
    printf("String please: ");
    scanf("%s", s);
    printf("Thanks for the %s!\n", s);
}