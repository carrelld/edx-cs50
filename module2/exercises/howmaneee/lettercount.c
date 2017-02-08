#include <stdio.h>
#include <cs50.h>
#include <string.h>

int lettercount(string word, char find);

int main(void)
{
	printf("goodbye: counting %c: %d\n", 'g', lettercount("goodbye", 'g'));
    printf("allofmylife all of my life: counting %c: %d\n", 'a', lettercount("allofmylife all of my life", 'a'));

}

int lettercount(string word, char find)
{
	int count = 0;
	for (int i = 0, n = strlen(word); i < n; i++)
	{
		//printf("word[%d] == %c == find %c T/F? %i \n", i, word[i], find, word[i] == find);
		if(word[i] == find)
		{
			count += 1;
		}
	}
	return count;
}