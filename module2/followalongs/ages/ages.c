 /**
  * Filename: ages.c
  * Save in Folder: ~/workspace/module2/followalongs/ages
  * 
  * Include the stdio library
  * Include the cs50 library
  * Add main method
  *   Declare a variable n of type int
  *   Do 
  *      Print "Number of people in room: "
  *      Assign user input to the variable n
  *   While(n < 1)
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  *
  */
  
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("Number of people in the room: ");
        n = GetInt();
    }
    while (n < 1);
    
    int ages[n];
    for (int i = 0; i < n; i++)
    {
        printf("Age of person #%i: ", i + 1);
        ages[i] = GetInt();
    }
    printf("Time passes...\n");
    for (int i = 0; i < n; i++)
    {
        printf("A year from now, person #%i will be %i years old.\n", i + 1, ages[i] + 1);
    }
}