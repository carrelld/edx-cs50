#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* f1 = fopen(argv[1], "r");
    
    printf("%d\n", (int) sizeof(f1));
    
    fclose(f1);
    
    return 0;
}