#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 5

int main(int argc, string argv[])
{
    string poke[5];
    for (int i = 0; i < MAX; i++)
    {
        printf("Give me a Pokemon: ");
        poke[i] = GetString();
    }
    printf("%s, I choose you!\n", poke[rand() % MAX]);
}