#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool customstrcmp(char* s1, char* s2);

int main(void){
    printf("\nString 1?: ");
    char* string1 = GetString();
    printf("\nString 2?: ");
    char* string2 = GetString();

    bool areEqual = customstrcmp(string1, string2);

    if (areEqual){
        printf("\nBingo! The strings are equal!\n");
    } else {
        printf("\nThe strings are not equal!\n");
    }
}

/**
 * customstrcmp
 * iterates through two strings, character by character
 * returns true if they are exactly the same, otherwise returns false
 */
bool customstrcmp(char* s1, char* s2)
{
    // Handle the passing of NULL pointers with error
    if (s1 == NULL || s2 == NULL)
    {
        return false;
        // error code here, but don't know how to pass error yet
    }
    
    // No match if different lengths
    if (strlen(s1) != strlen(s2))
    {
        return false;
    }
    
    // test each char for equivalence
    int i = 0;
    char a = *s1;
    char b = *s2;
    
    while (*(s1 +i) != '\0')
    {
        if(*(s1 + i) != *(s2 + i))
        {
            return false;
        }
        i++;
    }
    return true;
}