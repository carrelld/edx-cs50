 /**
  * Filename: conditions-0.c
  * Save in Folder: ~/workspace/module1/followalongs/conditions
  * 
  * Include the stdio library
  * Include the cs50 library
  * Add main method
  * (Hint: Don't forget to add curly braces { })
  *    Print "Please give me an int: "
  *    Declare a variable called n of type int and assign the user input to it.
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.  
  *
  */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Please give me an int: ");
    int n = GetInt();
    
    if (n > 0)
    {
        printf("You picked a positive integer!\n");
    }
    else
    {
        printf("You picked a negative integer!\n");
    }
}