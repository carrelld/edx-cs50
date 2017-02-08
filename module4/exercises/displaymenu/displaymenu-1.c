#include <stdio.h>
#include <cs50.h>


int main(int argc, char** argv)
{
    // Input validation
    if (argc != 2)
    {
        printf("usage: ./displaymenu <menufilepath>\n");
        return 1;
    }
    
    // display menu from file
    printf("Welcome to Better Burger, way better than Good Burger!\n");
    printf("MENU\n");
    FILE* file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("file not found! %s", __FILE__);
        return 1;
    }

    int count = 1;
    char c[256];   
    printf("%i: ", count++);
    while(fread(c, sizeof(char), 1, file) != 0)
    {
        printf("%c", *c);
        if (*c == '\n')
        {
            printf("%i: ", count++);
        }
        
    }
    
    // while(fread(line, sizeof(char), 256, file) != 0)
    // {
    //     printf("%i: %s", count++, line);
    // }
    printf("\n");
    fclose(file);
}