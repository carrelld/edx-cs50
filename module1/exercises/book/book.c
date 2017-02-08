#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("What's your favorit book? ");
    string book = GetString(); //function autmatically adds a newline
    printf("I love %s\n!", book);
    printf("...actually, %s is kind of meh.\n", book);
}