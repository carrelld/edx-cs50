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
    char line[256];       
    while(fgets(line, 256, file) != NULL)
    {
        printf("%i: %s", count++, line);
    }
    printf("\n");
    fclose(file);
}