/**
  * Part 2
  * Filename: guess5.c
  * Save in Folder: ~/workspace/module1/studios/guess5
  * 
  * Write another program called guess5, which gives the user only 5 chances to get the answer:
  * This should only involve some minor tweaking, so you can make a copy of your guess.c file using the cp command:
  *        $ cp guess.c guess5.c
  * Open up guess5.c and make changes there.
  *
  * Example:
  *     $ ./guess5
  *     I'm thinking of a number between 1 and 10. Can you guess what it is?
  *     Guess #1: 8
  *     Wrong!
  *     Guess #2: 5
  *     Wrong!
  *     Guess #3: 1
  *     Wrong!
  *     Guess #4: 7
  *     Wrong!
  *     Guess #5: 6
  *     Wrong!
  *     Sorry, you ran out of guesses.
  * 
  */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int answer = 6;
    
    printf("I'm thinking of a number between 1 and 10. Can you guess what it is?\n");
    int guess_count = 0;
    int guess;
    do
    {
        guess_count++;
        printf("Guess #%i ", guess_count);
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
    } while(1);
}