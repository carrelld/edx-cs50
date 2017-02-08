 /**
  * PART 3 
  * Filename: guessfive.c
  * Save in Folder: ~/workspace/module1/studios/guessfive
  *
  * Most likely, you've been using a while loop so far. Let's now refactor, and use a for loop instead, just for kicks.  
  * Write another program in a file called guessfive.c, which behaves exactly like guess5, but is implemented with a for loop. 
  * (But if you did use a for loop in guess5, then use a while loop here.)
  * 
  */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int answer = 6;
    
    printf("I'm thinking of a number between 1 and 10. Can you guess what it is?\n");
    int guess;
    
    for(int guess_count = 1; guess_count <= 5; guess_count++)
    {
        printf("Guess #%i: ", guess_count);
        guess = GetInt();
        if(guess == answer)
        {
            printf("Correct!\n");
            break;
        }
        else
        {
            printf("Wrong!\n");
            if(guess_count >= 5)
            {
                printf("Sorry, you ran out of guesses.\n");
                break;
            }
        }
    }
}