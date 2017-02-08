/**
  * Filename: sigma-0.c
  * Save in Folder: ~/workspace/module3/followalongs/sigma
  * 
  * Include the stdio library
  * Include the cs50 library
  * Add main method
  *    Declare a variable n of type int
  *    Do 
  *       Print "Positive Integer please: " 
  *       Assign the user input to the variable n. (Hint: Use the CS50 Library function GetInt())
  *    While n < 1
  *    Declare a variable called answer of type int and assign the expression "sigma(n)" to it
  *    Print the variable answer and a new line
  * 
  * You will find instructions to complete this task in the video. 
  * You will be modifying this code as you go along.
  *
  */
  
#include <cs50.h>
#include <stdio.h>

int sigma(int m);

int main(void)
{
    int n;
    do
    {
        printf("Positive integer please: ");
        n = GetInt();
    }
    while (n < 1);

    int answer = sigma(n);

    printf("%i\n", answer);
}

int sigma(int m)
{
    if (m < 1)
    {
        return 0;
    }
    
    int sum = 0;
    for (int i = 1; i <=m; i++)
    {
        sum += i;
    }
    return sum;
}