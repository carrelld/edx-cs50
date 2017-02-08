#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
	string menuItems[] = {"Water", "Soda", "Cheeseburger", "Fries"};

	// Display menu:
	printf("Welcome to Good Burger! Can I take your order?\n");
	printf("MENU:\n");
	for (int i = 0; i < 4; i++)
	{
		printf("Item %i: %s\n", i, menuItems[i]);
	}
	printf("\nHow many items?\n");

	int numItems = GetInt();

	// Open file
	FILE* file = fopen("order.txt", "w");
	if (file == NULL)
	{
	    printf("Error opening file for writing");
	    return 1;
	}

	for (int i = 0; i < numItems; i++)
	{
		printf("Which menu item would you like (0, 1, 2, or 3)?\n");
		// PUT YOUR CODE HERE: Take the order number, translate it into an item, and write the item to the file
        int ordered = GetInt();
        char* itemOrdered = menuItems[ordered];
        fwrite(itemOrdered, sizeof(char), strlen(itemOrdered), file);

		// PUT YOUR CODE HERE: Write a new line ("\n") to the file 
        fputc('\n', file);
	}

	fclose(file);

}