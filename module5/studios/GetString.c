#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

// Prototypes for the functions we need
string GetString(void);
void append(int c);

// Node structure definition
typedef struct node
{
    // The value to store in this node
    int n;
    // The link to the previous node in the list
    struct node* prev;
    // The link to the next node in the list
    struct node* next;
}
node;

// The head of our linked list
node* head = NULL;
// The tail of our linked list
node* tail = NULL;

// A simple main method to test our function
int main(void)
{
    printf("Please give me a string: \n");
    string x = GetString();
    printf("Thanks for the %s!\n", x);
}

string GetString(void)
{

    // Number of chars actually in buffer
    unsigned int n = 0;

    // Character read or EOF
    int c;

    // Iteratively get chars from standard input
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        // Append the character to our linked list
        append(c);
        // Update the number of characters
        n++;
    }

    // Return NULL if user provided no input
    if (n == 0 && c == EOF)
    {
        return NULL;
    }

    // Create a string to hold our result
    string minimal = malloc((n + 1) * sizeof(char));

    // Iterate through the list backward, adding each character from prepended list to the string
    node* curr = tail;

    for(int i = 0; i < n; i++)
    {
        minimal[i] = curr->n;
        curr = curr->prev;
    }

    // Terminate string
    minimal[n] = '\0';

    // Return string
    return minimal;
}

void append(int c)
{
    // Create a new node
    node* newNode = malloc(sizeof(node));
    newNode->n = c;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If the list is empty, our node is the only node
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        node* curr = head;
        // Prepend new char to list
        newNode->next = curr;
        curr->prev = newNode;
        head = newNode;
    }
}