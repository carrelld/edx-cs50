 /**
  * Filename: functions-0.c
  * Save in Folder: ~/workspace/module2/followalongs/functions
  * 
  * Include the stdio library
  * Include the cs50 library
  * Add main method
  *   Print "Your name: "
  *   Declare a variable s of type string and assign the user input to it 
  *   (Hint: use cs50 library function GetString())
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  *
  */
  
#include <stdio.h>
#include <cs50.h>

void PrintName(string);

int main(void)
{
    printf("Your name: ");
    string s = GetString();
    PrintName(s);
}

void PrintName(string name)
{
    printf("hello, %s\n", name);
}
