#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    printf("Whaddaya say, kid?\n");
    char* s = GetString();
    if (s == NULL)
    {
        return 1;
    }
    
    int copy_size = strlen(s) * 2 + 1;
    char* s_twice = malloc(copy_size * sizeof(char));
    if (s_twice == NULL)
    {
        return 1;
    }
    
    for (int i = 0, j = 0; i < copy_size; i++, j++)
    {
        if (s[j] == '\0' && i < copy_size - 1)
        {
            j = 0;
        }
        s_twice[i] = s[j];
        // printf("debug: i==%i j==%i s_twice==%c\n", i, j, s_twice[i]);
    }
    
    printf("%s\n", s_twice);
}