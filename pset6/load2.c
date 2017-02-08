#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 128
typedef char BYTE;

bool load(FILE* file, BYTE** content, size_t* length)
{
    
    // Get size needed for buffer
    fseek( file , 0L , SEEK_END);
    *length = ftell(file);
    rewind(file);
    
    // Malloc needed space for reading entire file
    *content = calloc(1, *length + 1);
    if (!*content)
    {
        printf("memory allocation failed!\n");
        //error(500);
        return false;
    }
    
    // Read in data and check for error
    if (1 != fread(*content, *length, 1, file))
    {
        printf("Error reading file!\n");
        //error(500);
        return false;
    }
    
    // Cleanup
    return true;
}

int main(void)
{
    FILE* file = fopen("/home/ubuntu/workspace/pset6/public/smallfile.txt", "r");
    BYTE* content;
    size_t length = 0;
    load(file, &content, &length);
    
    printf("length: %d\n", (int) length);
    printf("content:%s\n", content);
}