/**
 * trie.h
 * 
 * methods declarations and definitions for Trie data structure
 * for case-insensitive words with letters a-z and apostrophes
 * 
 * 
 */


// Trie definitions
#define NUM_LEGAL_CHARACTERS 27

typedef struct TrieNode {
    // If a node is the end of a loaded word, this is 1
    int isWord;
    struct TrieNode* next[NUM_LEGAL_CHARACTERS]; 
} TrieNode;

/**
 * Create and initialize a nodes values to NULL or 0 depending on type
 */
TrieNode* InitNode();

/**
 * Return child node at trienode pointer array index
 */
TrieNode* GetChild(TrieNode* t, int index);

/**
 * Connect a child node at next* array index to TrieNode t, return pointer to new child
 */
TrieNode* AddChild(TrieNode* t, int index);

/**
 * Convert alpha char and apostrophe to index value
 */
int CharToIndex(char c);

/**
 * Add key to trie structure
 */
int AddKey(TrieNode* t, char* key);

/**
 * Return Number of words loaded into the trie
 */
int GetTrieSize();

/**
 * Set the variable that indicates the number of words loaded in the trie
 * Changing this will NOT change the structure of the trie, so you should never
 * use this function without some change to the trie's actual contents.
 */
void SetTrieSize(int n);

/**
 * release all malloc'd nodes starting at t
 */
int FreeTrie(TrieNode* t);

/**
 * Check trie t for the word word
 */
int InTrie(TrieNode* t, const char* word);
