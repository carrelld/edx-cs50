/**
  * Filename: letterlocator.c
  * Save in Folder: ~/workspace/module2/studios/letterlocator
  * 
  * In a file called letterlocator.c write a program that prompts the user for an alphabetic character, 
  * and then prints the position of that letter in the alphabet, starting with A at position 0. 
  * Your program should work for both capital and lowercase letters, but should reject any input that is not alphabetical, like '3' or '$'.
  *
  * Example:
  * $ ./letterlocator
  * Give me a letter: A
  * A is at position 0
  * $ ./letterlocator
  * Give me a letter: e
  * e is at position 5
  * $ ./letterlocator
  * Give me a letter: @
  * Give me a letter: Y
  * Y is at position 25
  *
  * (Hint: cs50 Library functions GetChar() and isAlpha() will be helpful)
  *
  */


#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    char c;
    do
    {
        printf("Give me a letter: ");
        c = GetChar();
    } while (!isalpha(c));
    
    int c_pos = (c >= 'a') ? c - 'a' : c - 'A';
    
    printf("%c is at position %d\n", c, c_pos);
}