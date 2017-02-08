/*
Purpose: implement a caesar cypher by adding k places to each letter, wrapping
around when necessary
Author: Dave Carrell
Date: 2016 - 02 - 02
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage: caesar int");
        return 1;
    }
    
    int key = atoi(argv[1]) % 26;
    if (key < 0)
        return 1;
    
    string phrase = GetString();
    
    //cypher convert and output
    for (int i = 0, n = strlen(phrase); i < n; i++)
    {
        
        //handle non-alpha character
        if(!isalpha(phrase[i]))
        {
            printf("%c", phrase[i]);
            continue;
        }
        //phrase[i] is the character
        //subtract 'a' or 'A' based on case
        //add key, mod with 26 to wrap around, and add back 'a' or 'A'
        char p_offset = isupper(phrase[i]) ? 'A' : 'a';
        char encrypted = phrase[i] - p_offset;
        encrypted += key;
        encrypted %= 26;
        encrypted += p_offset;
        printf("%c", encrypted);
        
    }
    printf("\n");
    return 0;
}