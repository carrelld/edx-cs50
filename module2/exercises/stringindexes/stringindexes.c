/*
Exercise: String with Indexes
Write a program that receives a string from the user, and then loops over the string and prints each character along with the index of that character, like so:

$ ./stringindexes
Give me a string please: Bagel
The character at index 0 is B
The character at index 1 is a
The character at index 2 is g
The character at index 3 is e
The character at index 4 is l
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("Give me a string please: ");
    string s = GetString();
    
    if (s != NULL)
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            printf("The character at index %d is %c\n", i, s[i]);
        }
    }
}