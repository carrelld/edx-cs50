#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
	int count = 0;
	for (;;)
	{
	    count++;
		int* a = malloc(4);
		if (a == NULL)
        {
			printf("%i", count);
			return 1;
        }
	}
}
