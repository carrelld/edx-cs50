/**
* Filename: compare-0.c
* Save in Folder: ~/workspace/module4/followalongs/compare
* 
* Include the cs50 library
* Include the stdio library
*
* Add main method
*    Print "Say something: " 
*    Declare a variable called s of type string and assign the user input to it
*    Hint: Use the function GetString() from the cs50 library.
* 
*    Print "Say something: " 
*    Declare a variable called t of type string and assign the user input to it   
*
*    If (s == t)
*        Print "You typed the same thing!\n"
*    Else
*        Print "You typed different things!\n"
*
* You will find instructions to complete this task in the video. 
* You will be modifying this code as you go along.
*
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Say something: ");
    string s = GetString();
    
    printf("Say something: ");
    string t = GetString();

    if (s == t)
    {
        printf("You typed the same thing!\n");
    }
    else
    {
        printf("You typed different things!\n");
    }
}