/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"
#include "trie.h"

TrieNode* trienode;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    if(InTrie(trienode, word))
    {
        //printf("Word Found: %s\n", word);
        return true;
    }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    
    // Load text from file "dictionary" into a trie data structure
    
    // Open file
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Couldn't open file\n");
        return false;
    }
    
    // Initialize Trie root
    trienode = InitNode();
    
    
    
    // Read each line and add to trie structure
    int buffersize = LENGTH + 2; // Not entirely sure why +1 doesn't work...
    char line[buffersize];
    while(fgets(line, buffersize, fp) != NULL)
    {
        AddKey(trienode, line);
    }
    
    
    // Cleanup and return
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return GetTrieSize();
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    if(FreeTrie(trienode))
    {
        SetTrieSize(0);
        return true;
    }
    return false;
}
