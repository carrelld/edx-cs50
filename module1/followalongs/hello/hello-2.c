 /**
  * Filename: hello-2.c
  * Save in Folder: ~/workspace/module1/followalongs/hello
  * 
  * Include the stdio library
  * Add main method
  * (Hint: Don't forget to add curly braces { })
  *    Print "State your name: "
  *    Print "hello, " and a new line 
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  *
  */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("State your name: ");
    //add a function GetString() from the cs50.h library to get input
    string name = GetString();
    printf("Hello, %s!\n", name);
}