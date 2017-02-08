/*
purpose: print three 3-letter command-line arguments vertically in adjacent columns

specs:
make sure the user provided exactly 3 additional command-line arguments (in addition to the name of the program itself).
make sure each of those arguments is exactly 3 characters-long. (Use strlen())

author: Dave Carrell
date: 2016-02-11
*/

/* Filename: wordgrid.c
  * Save in Folder: ~/workspace/module3/studios/wordgrid
  * 
  * Recall that you can represent multi-dimensional data with nested arrays. 
  * For example, you can represent a grid of things as an array of (arrays of things).
  * In fact, an array of strings is one such example; since a string is actually just an array of chars, 
  * an array of strings is an array of (arrays of chars).
  * Let's explore this by writing a program that receives three 3-character strings (in other words a grid of 9 chars),
  * and prints the grid to the console, with each word in its own column, like so:
  * 
  * Example:
  * $ ./wordgrid sun yes ear
  * sye
  * uea
  * nsr
  * 
  * Notice how each word is written downwards, rather than across.
  * 
  * First you'll want to perform some validation:
  * Make sure the user provided exactly 3 additional command-line arguments 
  * (in addition to the name of the program itself).
  * Make sure each of those arguments is exactly 3 characters-long. (Use strlen())
  * After validating, you can go about printing the grid.
  * 
  * Note that you can access the elements of a nested array using multiple brackets, i.e. [][]. 
  * For example, if words looks like:
  * 
  * [ "sun", "yes", "ear" ]
  * , then:
  *
  * words[0][0] evaluates to "sun"[0] which evaluates to 's'
  * words[2][1] evaluates to "ear"[1] which evaluates to 'a'
  *
  */

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // argument validation
    if (argc != 4)
    {
        printf("Please use 3 arguments of length 3");
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        if (strlen(argv[i]) != 3)
        {
            printf("Please use 3 arguments of length 3");
            return 1;
        }
    }
    
    // print the args in columns
    for (int i = 0; i < 3; i++) // cycle characters
    {
        for (int j = 1; j < 4; j++) // cycle arguments
        {
            printf("%c", argv[j][i]);
        }
        printf("\n");
    }
}