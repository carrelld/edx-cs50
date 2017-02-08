/**
 * trie.c
 * 
 * implementations for trie.h
 * 
 * Author: Dave Carrell
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "trie.h"

int TrieSize = 0;

TrieNode* InitNode()
{
    TrieNode* trienode = malloc(sizeof(TrieNode));
    //trienode->data = c; // Not used anywhere, but seems potentially useful?
    trienode->isWord = 0;
    // Is this even necessary? init node array to null, seems to be done automatically
    // for (int i = 0; i < NUM_LEGAL_CHARACTERS; i++)
    // {
    //     trienode->next[i] = NULL;
    // }
    return trienode;
}

TrieNode* GetChild(TrieNode* t, int index)
{
    return t->next[index];
}

TrieNode* AddChild(TrieNode* t, int index)
{
        
        TrieNode* child = GetChild(t, index);
        
        if (!child)
        {
            child = InitNode();
        }
        
        t->next[index] = child;
        
        return child;
}

int AddKey(TrieNode* t, char* key)
{
    if (!t)
    {
        printf("Root is NULL\n");
        return 1;
    }
    
    for (int i = 0, n = strlen(key) - 1; i < n; i++)
    {
        // add child to t and progress to the child node pointer
        t = AddChild(t, CharToIndex(key[i]));
    }
    
    // Add key as word if not a duplicate entry
    if(t->isWord == 0)
    {
        t->isWord = 1;
        TrieSize++;
    }
    return 0;

}

int CharToIndex(char c)
{
    // Function can accept characters < '\'' and characters > 'z', but this 
    // checking was done in the speller.c
    
    // index 0 is apostrophe, 1-26 is a-z
    // Why did this work if I just did c - 96? if c was '\'', it would return -57
    // and it can't be good to have a negative index
    // Anyway, it's fixed now by this ternary operator

    return c == '\'' ? c - '\'' : c - 96;
}

int GetTrieSize()
{
    return TrieSize;
}

void SetTrieSize(int n)
{
    TrieSize = n;
}

int FreeTrie(TrieNode* t)
{
    // recursively destroy entire tree from node given
    
    for (int i = 0; i < NUM_LEGAL_CHARACTERS; i++)
    {
        if (t->next[i] != NULL)
        {
            FreeTrie(t->next[i]);
        }
    }
    
    free(t);
    return 1;
    
}

int InTrie(TrieNode* t, const char* word)
{
    // if trie root pointer is null, the word can't be in the data
    if (t == NULL)
    {
        return 0;
    }
    
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Crawl to next node based on chars in word
        t = GetChild(t, CharToIndex(tolower(word[i])));
        
        // t==NULL means we reached a pointer that doesn't have a node before the end of our word, so it's not in the list
        if (t == NULL)
        {
            return 0;
        }
    }
    
    // Verify that the word at this pointer was in fact stored and not just a part of a larger word
    return t->isWord;
}
