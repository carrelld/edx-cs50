/*
Purpose: implement a vigenere cypher using a user-inputted key of alpha characters, wrapping
around when necessary
Author: Dave Carrell
Date: 2016 - 02 - 02
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char encrypt(int key, char plain);

int main(int argc, char **argv)
{
    //User error handling
    if(argc != 2)
    {
        printf("Usage: vigenere string\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if(isalpha(argv[1][i]))
        {
            continue;
        }
        else
        {
            printf("Usage: vigenere string\n");
            return 1;
        }
    }
    
    //user input and modification
    string phrase = GetString();
    
    //cypher convert and output
    int key_len = strlen(argv[1]);
    for (int i = 0, key_index = 0, n = strlen(phrase); i < n; i++)
    {
        //change key phrase index to offset value
        int key_offset = tolower(argv[1][key_index] - 'a');
        //printf("%c", key_offset + 'a'); //debug to check how encryption phrase advances
        char encrypted = encrypt(key_offset, phrase[i]);
        //printf("%c", encrypted);
        
        //advance encryption phrase character iif encrypted letter was alpha
        if(isalpha(encrypted))
            key_index = (key_index + 1) % key_len;
    }
    printf("\n");
    return 0;
}

char encrypt(int key, char plain)
{
        //handle non-alpha character
        if(!isalpha(plain))
        {
            //printf("%c", plain);
            return plain;
        }
        
        
        //plain is the character
        //subtract 'a' or 'A' based on case
        //add key, mod with 26 to wrap around, and add back 'a' or 'A'
        
        char p_offset = isupper(plain) ? 'A' : 'a';
        char encrypted = plain - p_offset;
        encrypted += key;
        encrypted %= 26;
        encrypted += p_offset;
        printf("%c", encrypted);
        //printf("key: %i, %c, plain: %i, %c, encrypted: %i, %c\n", key, key, plain, plain, encrypted, encrypted);
        return encrypted;
}