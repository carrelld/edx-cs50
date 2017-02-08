/**
  * Filename: scanf-1.c
  * Save in Folder: ~/workspace/module5/followalongs/scanf
  * 
  * Include the stdio library
  *
  * Add main method
  *    Declare a pointer called s of type char 
  *    Print "String please: " 
  *    Scan the user input using "s" as the value for the placeholder %s
  *    Print "Thanks for the %s!\n" 
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  *
  */


#include <stdio.h>

int main(void)
{
    char* s = NULL;
    printf("String please: ");
    scanf("%s", s);
    printf("Thanks for the %s!\n", s);
}