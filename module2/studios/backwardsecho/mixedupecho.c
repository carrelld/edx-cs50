/*
program to echo command-line arguments back to the user. words must be given in reverse.
author: Dave Carrell
date: 2016-02-02

Part 2: Mixed-up Echo
Now for another variation on the "echo" theme. In a file called mixedupecho.c 
write another program that accepts some command-line arguments and then echoes 
them back to the console.

The twist this time: the echoes should "intermix" with each other, like so:

$ ./mixedupecho HELLO!
.H/EmLiLxOe!dHuEpLeLcOh!oH
For this program, you can ignore any command-line arguments beyond the first 
two (including the program name itself):

$ ./mixedupecho HELLO! morestuff lalala
.H/EmLiLxOe!dHuEpLeLcOh!oH
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Error: Too few arguments");
        return 1;
    }
    
    int lenargv[2] = {strlen(argv[0]), strlen(argv[1])};
    int n = lenargv[0] > lenargv[1] ? lenargv[0] : lenargv[1]; //max arg length
    
    int index[2];
    for (int i = 0; i < n; i++)
    {
        //establish index counter based on mod of argument's length
        index[0] = i % lenargv[0];
        index[1] = i % lenargv[1];
        
        printf("%c%c", argv[0][index[0]], argv[1][index[1]]);
    }
    printf("\n");
}
