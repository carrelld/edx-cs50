#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 128
typedef char BYTE;

bool load(FILE* file, BYTE** content, size_t* length)
{
    
    // Initial allocation
    *content = calloc(1, BUFFER_SIZE + 1);
    *length = 0;
    
    // Vars needed for fread loop
    int bytesRead = 0;
    char* crawler = *content;
    int i = 2;
    
    while ((bytesRead = fread(crawler, 1, BUFFER_SIZE, file)) > 0)
    {
        *length += bytesRead;
        *content = realloc(*content, i++ * BUFFER_SIZE + 1);
        crawler = *content + *length;
    }
    
    printf("*length: %d\n\n", (int) *length);
    printf("*content:\n\n%s\n\n", *content);
    
    // Cleanup
    return true;
}

int main(void)
{
    FILE* file = fopen("/home/ubuntu/workspace/pset6/public/smallfile.txt", "r");
    BYTE* content;
    size_t length = 0;
    load(file, &content, &length);
    
    //printf("length: %d\n", (int) length);
    //printf("content:%s\n", content);
}