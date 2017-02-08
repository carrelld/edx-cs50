#include <cs50.h>
#include <stdio.h>

void printArray(int* a);
void addElement(int** a, int element);
int SIZE = 0;

int main(void)
{
	int* a = malloc(0);
	addElement(&a, 7);
	printArray(a);
}

void printArray(int* a)
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%i, ", *(a + i));
	}
}

void addElement(int** a, int element)
{
	// alocate enough space for new element
	int* b = malloc(SIZE * sizeof(int) + sizeof(int));
	
	// copy array
	for (int i = 0; i < SIZE; i++)
	{
		*(b + i) = *(*a + i);
	}
	*(b + SIZE) = element;
	SIZE++;
	*a = b;
	free(b);
}