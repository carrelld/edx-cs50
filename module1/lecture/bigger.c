#include <stdio.h>
#include <cs50.h>

int main(void)
{
	printf("Please provide interger 1: ");
	int x = GetInt();
	printf("Please provide integer 2: ");
	int y = GetInt();
	if(x == y)
	{
		printf("Those are equal\n");
	}
	else
	{
		printf("%i is bigger\n", x > y ? x: y);
	}
}