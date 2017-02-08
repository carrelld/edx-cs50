#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

typedef char BYTE;

char* indexes(const char* path)
{
    // Allocate some memory for what will ultimately be returned
    char* indexPath;
    indexPath = malloc((strlen(path) + 12) * sizeof(char));
    strcpy(indexPath, path);
    
    // Check for index.php
    strcpy(indexPath + strlen(path), "/index.php\0");
    printf("indexPath1:\t%s\n", indexPath);
    if (access(indexPath, F_OK) != -1) 
    {
        printf("file exists\n");
        return indexPath;
    }
    
    // Check for index.html
    strcpy(indexPath + strlen(path), "/index.html\0");
    printf("indexPath2:\t%s\n", indexPath);
    if (access(indexPath, F_OK) != -1) 
    {
        printf("file exists\n");
        return indexPath;
    }
    
    free(indexPath);
    return NULL;
}

int main(void)
{
    const char* path = "/home/ubuntu/workspace/pset6/public/test";

    indexes(path);
}