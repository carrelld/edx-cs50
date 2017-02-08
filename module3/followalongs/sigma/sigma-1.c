/**
  * This is a continuation of the last program and you should copy sigma-0.c so you do not have to 
  * write the whole program. Use the command below, open up sigma-1.c and watch the video
  * to complete the task.  
  * Make sure you are in this Folder: ~/workspace/module3/followalongs/sigma
  *
  *      cp sigma-0.c sigma-1.c
  *
  * Afterwards, step through your program in the IDE Debugger, just like they did in class.
  */
  
  
#include <cs50.h>
#include <stdio.h>

int sigma(int m);

int main(void)
{
    int n;
    do
    {
        printf("Positive integer please: ");
        n = GetInt();
    }
    while (n < 1);

    int answer = sigma(n);

    printf("%i\n", answer);
}

int sigma(int m)
{
    if (m <= 0)
    {
        return 0;
    }
    else
    {
        return m + sigma(m - 1);
    }
}