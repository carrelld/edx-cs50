/*
Exercise: How Maneee
howmaneee.c is a program that is supposed to count the occurrances of the 
letter 'e' in a string provided by the user:

$ ./howmaneee
Type some stuff: Why hello there
The thing you just typed contains 3 'e's!
Unfortunately, there's something wrong with it. See if you can spot the bug 
and fix it.
*/

/**
 * howmaneee.c
 * Calculates the number of occurances of the character 'e' found within the user's input 
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>

// FIXME there's something wrong with this code. It's not working!
int main(void)
{
  printf("Type some stuff: ");
  string userinput = GetString();

  // count the occurrances of the letter 'e'
  int len = strlen(userinput), counter = 0; // moved counter to outside loop
  for (int i = 0; i < len; i++)
  {
    if (userinput[i] == 'e')
    {
      counter++;
    }
  }

  printf("The thing you just typed contains %i 'e's!\n", counter);
}