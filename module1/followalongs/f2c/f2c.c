 /**
  * Filename: f2c.c
  * Save in Folder: ~/workspace/module1/followalongs/f2c
  * 
  * Include the stdio library
  * Include the cs50 library
  * Add main method
  * (Hint: Don't forget to add curly braces { })
  *    Print "Temperature in F: "
  *    Declare a variable called f of type float and assign the user input to it.
  *    (Hint: We can get user input of type float using the cs50 library function GetFloat())
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  *
  */
  
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Temperature in F: ");
    float f = GetFloat();
    
    //without ".0", int / int results in integer division
    //adding ".0" uses floating point division instead
    float c = 5.0 / 9.0 * (f - 32.0);
    
    printf("%.1f\n", c);
}