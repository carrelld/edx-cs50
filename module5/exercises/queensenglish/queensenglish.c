#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char myChar;
    struct node* next;
} node;

int InsertNode(node* current, char insertvalue);

node* stringToList(char* inputString)
{
    node* first = malloc(sizeof(node));
    first->myChar = 'a';
    first->next = NULL;
    node* current = first;

    char* s;
    for(s = inputString; *s != '\0'; s++)
    {
        node* newNode = malloc(sizeof(node));
        newNode->myChar = *s;
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    return first->next;
}

char* listToString(node* firstChar)
{
    // get the length of the string
    int totalLen = 0;
    node* current = firstChar;
    while(current != NULL)
    {
        totalLen++;
        current = current->next;
    }

    char *newString = malloc(sizeof(char)*(totalLen+1));
    char *iter = newString;
    current = firstChar;
    for (int i = 0; i < totalLen; i++)
    {
        *iter = current->myChar;
        current = current->next;
        iter++;
    }
    *iter = '\0';
    return newString;
}

int main(void)
{
    // Read in an input string
    printf("Input string?: \n");
    char* myString = GetString();

    // Convert that string into a linked list
    node* firstChar = stringToList(myString);

    // TODO: Your code here! Loop through the list, and every time you see an 'o',
    // insert a 'u' afterwards
    node* current = firstChar;
    while(current != NULL){
        if (current->myChar == 'o')
        {
            InsertNode(current, 'u');
        }
        
        current = current->next;
    }

    // convert the list back into a string
    char* newString = listToString(firstChar);

    // print out the "corrected" string
    printf("Charlatan! I use the Queen's English:\n");
    printf("%s\n", newString);
}

int InsertNode(node* current, char insertvalue)
{
    // Create and initiallize a new node with specified value
    node* insert = malloc(sizeof(node));
    if (insert == NULL)
    {
        printf("Memory allocation error\n");
        return 3;
    }
    insert->myChar = insertvalue;
    insert->next = NULL;
    
    // Modify pointers to include new node after current node
    insert->next = current->next;
    current->next = insert;
    
    return 0;
}