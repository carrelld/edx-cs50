/*
Exercise: Command-line Calculator
Let's practice using command line arguments by implementing a simple command line adder.

The progam should expect the user to provide two command line arguments, which are numbers, then print out the result of adding them together.

This exercise is like a combination of these two videos:

argv-0
Adder
So if you need help, look at those first!

Usage for the program should look like this:

$ ./clc 5 2
Result: 7.000000000
$ ./clc 2.2 3.3
Result: 5.500000000
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if(argc != 3)
    {
        printf("Please enter 2 operands.\n");
        return 1;
    }
    
    float op[2];
    for (int i = 1; i < argc; i++)
    {
        op[i-1] = atof(argv[i]);
    }
    
    printf("Result: %f\n", op[0] + op[1]);
}