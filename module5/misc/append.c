#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node* next;
} node;

void Append(int value, node** list);
void PrintList(node* list);
int FreeList(node* head);
int LenList(node* list);
int SumList(node* list);

int main(void)
{
    node* head = NULL;
    Append(4, &head);
    Append(3, &head);
    Append(7, &head);
    PrintList(head);
    printf("len of list: %i\n", LenList(head));
    printf("sum of list: %i\n", SumList(head));
    FreeList(head);
}

void Append(int value, node** list)
{
    node* newNode = malloc(sizeof(node));
    newNode->num = value;
    newNode->next = NULL;
    
    if (*list == NULL)
    {
        *list = newNode;
    }
    else
    {
        node* crawler = *list;
        while(crawler->next != NULL)
        {
            crawler = crawler->next;
        }
        crawler->next = newNode;
    }
}

void PrintList(node* list)
{
    node* crawler = list;
    if (crawler == NULL)
    {
        printf("[empty list]\n");
    }
    else
    {
        while(crawler != NULL)
        {
            printf("%d\n", crawler->num);
            crawler = crawler->next;
        }
    }
}

int FreeList(node* head)
{
    if (head == NULL)
    {
        free(head);
        return 0;
    }
    
    node* curNode = head;
    
    while(curNode != NULL)
    {
        node* nextNode = curNode->next;
        free(curNode);
        curNode = nextNode;
    }
    
    return 0;
    
}

int LenList(node* list)
{
    node* crawler = list;
    int count = 0;
    while(crawler != NULL)
    {
        count += 1;
        crawler = crawler->next;
    }
    
    return count;
}

int SumList(node* list)
{
    node* crawler = list;
    int sum = 0;
    while(crawler != NULL)
    {
        sum += crawler->num;
        crawler = crawler->next;
    }
    
    return sum;
}