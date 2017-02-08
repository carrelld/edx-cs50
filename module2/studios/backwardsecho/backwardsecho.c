/*
program to echo command-line arguments back to the user. words must be given in reverse.
author: Dave Carrell
date: 2016-02-02
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    int n;
    for (int i = 0; i < argc; i++)
    {
        n = strlen(argv[i]);
        //printf("strlen(argv[%d]): %d\n", i, n); //debug for length of input
        for (int j = n - 1; j >= 0; j--)
        {
            printf("%c", argv[i][j]);
        }
        printf(" ");
    }
    printf("\n");
}
