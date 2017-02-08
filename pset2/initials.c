/*
Purpose: Use GetString() to retieve a name from the user then output the
initials of the name
Author: Dave Carrell
Date: 2016 - 02 - 02
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //printf("What's your name? ");
    string name = GetString();
    
    printf("%c", toupper(name[0]));
    for (int i = 1, n = strlen(name); i < n; i++)
    {
        if(name[i] == ' ')
        {
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
}