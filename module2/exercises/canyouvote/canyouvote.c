/*
Help the user figure out if their friends can vote! For the purposes of the exercise, someone can vote as long as they are 18 or older.

We want the user to tell us:

how many people to check
Then prompt the user for each age one-by-one. After that, for each person, we’ll output if they can vote or not (if they’re at least 18 or not).

Basic template code is provided in canyouvote.c

This exercise is very similar to the ages walkthrough; if you need help, look there first!

Your program should work like this:

$ ./canyouvote
How many people want to vote? 3
Age of person 1: 22
Age of person 2: 30
Age of person 3: 14
Person 1 can vote!
Person 2 can vote!
Person 3 cannot vote :(
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("How many people want to vote? ");    
        n = GetInt();
    }
    while (n < 1);
    
    int ages[n];
    for (int i = 0; i < n; i++)
    {
        printf("Age of person %i: ", i + 1);
        ages[i] = GetInt();
    }
    
    for (int i = 0; i < n; i++)
    {
        if (ages[i] < 18)
        {
            printf("Person %i cannot vote :(\n", i + 1);
        }
        else
        {
            printf("Person %i can vote!\n", i + 1);
        }
    }
}