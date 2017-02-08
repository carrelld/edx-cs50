#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* ptr = malloc(sizeof(char) * 7);

    for (int i = 0; i < 6; i++)
        *(ptr + i) = 'z';

    ptr[6] = '\0';

    while (*ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }

    free(ptr-6);
}