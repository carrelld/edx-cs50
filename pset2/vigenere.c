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

char encrypt(char p, char k);

int main(int argc, char **argv)
{
    //User error handling
    {
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
    }
    
    //user input and useful vars needed for keyword index tracking
    string plaintext = GetString();
    string keyword = argv[1];
    int len_keyword = strlen(keyword);
    int index_keyword = 0;
    
    //encrypt and output
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char encrypted = encrypt(plaintext[i], keyword[index_keyword]);
        printf("%c", encrypted);
        
        //separate incrementor for keyword index to handle non-encrypted chars
        if(isalpha(encrypted))
            index_keyword = (index_keyword + 1) % len_keyword;
    }
    
    printf("\n");
    return 0;
}

char encrypt(char p, char k)
{
        /*
        usage: encrypt('A' using key 'B')
        purpose: change input alpha to a different character using a caesar 
        cypher based on provided character key.
        */
        
        //don't encrypt non-alpha characters
        if(!isalpha(p))
        {
            return p;
        }
        
        //offset values 'a' or 'A' is 0, necessary for mod to work
        char p_offset = isupper(p) ? 'A' : 'a';
        k = toupper(k) - 'A';   //should be 0-25
        char e = (p - p_offset + k) % 26 + p_offset;
        
        //debug
        //printf("%c, %c, %c, %c\n", p, p_offset, k, e);
        
        return e;
}