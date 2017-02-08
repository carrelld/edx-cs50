 /**
  * Filename: guess.c
  * Save in Folder: ~/workspace/module1/studios/guess
  * 
  * Part 1
  * Write a "guessing game" program that allows the user to guess a number between 1 and 10.
  * The program should continuously reprompt the user until they get the correct answer.
  * 
  * You can simply decide on a "correct answer" and hard-code that number into your code. 
  * Supposing for example that you decide to make 4 the correct answer, you will probably have a line like this:
  *     
  *     int answer = 4;
  * 
  * Notice that you'll need to keep track of how many guesses have happened so far, so that you can properly print "Guess #<n>"
  * Example: 
  * 
  *     I'm thinking of a number between 1 and 10. Can you guess what it is?
  *     Guess #1: 5
  *     Wrong!
  *     Guess #2: 9
  *     Wrong!
  *     Guess #3: 4
  *     Correct!
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
        }
        else
        {
            printf("Wrong!\n");
        }
    } while(guess != answer);
}