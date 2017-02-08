#include <stdio.h>
#include <cs50.h>

int main(void)
{
	int answer = 1;
	printf("I'm thinking of a number between 1 and 10. Can you guess what it is?\n");
	
	for(int i = 0; i < 5; i++)
	{
		printf("Guess #%i: ", i + 1);
		int guess = GetInt();
		
		if(guess == answer)
		{
			printf("CORRECT!!!!!!!!!!!!!!!!!!!!!!!!\n");
			i = 10;
		}
		else
		{
			printf("WRONG!\n");
		}
	}
}