#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string input = GetString();
    for (int i = 0; i < strlen(input); i++)
    {
        printf("%c, %i\n", isalpha(input[i]), isalpha(input[i]));
    }
    printf("%c\n", 65);
}