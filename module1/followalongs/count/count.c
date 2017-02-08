/**
  * Filename: count.c
  * Save in Folder: ~/workspace/module1/followalongs/count
  * 
  * Include the stdio library
  * Include the cs50 library
  * Add main method
  * (Hint: Don't forget to add curly braces { })
  *    Print "Please enter a number: "
  *    Declare a variable called num of type int and assign the user input to it.
  *    Assign the expression num / 2 to the variable num
  *    Print "Your halved number is: %i\n" using num as the value for the placeholder %i
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  * 
  */

#include <stdio.h>
#include <cs50.h>

void f()
{
    printf("Hello, world\n");
}

int main(void)
{
    printf("Please enter a number: ");
    
    int num = GetInt();
    
    printf("DEBUG before: %i\n", num);    
    num = num / 2 + 1;
    printf("DEBUG after: %i\n", num);
    
    for (int i = 1; i < num; i++)
    {
        printf("%i!\n", i);
    }
    
    return 0;
    
}