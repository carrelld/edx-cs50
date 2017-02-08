 /**
  * Filename: scanf-0.c
  * Save in Folder: ~/workspace/module5/followalongs/scanf
  * 
  * Include the stdio library
  *
  * Add main method
  *    Declare a variable called x 
  *    Print "Number please: " 
  *    Scan the user input using "&x" as the value for the placeholder %i
  *    Print "Thanks for the %i!\n" 
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  *
  */

#include <stdio.h>

int main(void)
{
    int x;
    printf("Number please: ");
    scanf("%i", &x);
    printf("Thanks for the %i!\n", x);
}