 /**
  * Filename: adder.c
  * Save in Folder: ~/workspace/module1/followalongs/adder
  * 
  * Include the stdio library
  * Include the cs50 library
  * Add main method
  * (Hint: Don't forget to add curly braces { })
  *    Print "Please give me an int: "
  *    Declare a variable called x of type int 
  *    Declare a variable called y of type int 
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  *
  */
  
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Please give me and int: ");
    int x = GetInt();
    
    printf("Please give me another int: ");
    int y = GetInt();
    
    printf("The sum of %d and %d is %d.\n", x, y, x + y);
}