  /**
   * Filename: repeat.c
   * Save in Folder: ~/workspace/module1/studios/repeat
   *
   * In a file called repeat.c write a program that repeats a phrase multiple times. 
   * You program should prompt the user for both a phrase, and a number of repeats.
   * 
   * Example:
   * $ ./repeat
   * Give me a phrase: I am NOT a talking robot!
   * How many times should I say it? 5
   * I am NOT a talking robot!
   * I am NOT a talking robot!
   * I am NOT a talking robot!
   * I am NOT a talking robot!
   * I am NOT a talking robot!
   * 
   * Twist 1: VALIDATE - Your program should only accept values that are at least 1, and no greater than 100 
   * for the "how many times" argument. If the user fails supply a number within that range, 
   * the program should continue prompting until they do.
   * 
   * Example:
   * $ ./repeat
   * Give me a phrase: Oh na na, what's my name.
   * How many times should I say it? (between 1 and 100): -4
   * How many times should I say it? (between 1 and 100): 238
   * How many times should I say it? (between 1 and 100): 2
   * Oh na na, what's my name.
   * Oh na na, what's my name.
   * 
   * 
   */
   
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /* User input */
    string user_phrase;
    printf("Give me a phrase: "); 
    user_phrase = GetString();
    int num_repeat = 0;
    while(num_repeat < 1 || num_repeat > 100)
    {
        printf("How many times should I say it? (between 1 and 100): ");
        num_repeat = GetInt();
    }
    
    /* Program output */
    for(int i = 0; i < num_repeat; ++i)
    {
        printf("%s\n", user_phrase);
    }
    
    return 0;
}