#import <stdio.h>

typedef struct Node {
  // Node* rep;
  struct Node* next;
  char value;
} Node;

void InsertNode(Node* curNode, Node* nextNode);
void TransverseNode(Node* node);

int main(void)
{
  char a[4] = {'t', 'e', 's', 't'};

  // init node array
  Node node0, node1, node2, node3;
  node0.next = NULL;
  node1.next = NULL;
  node2.next = NULL;  
  node3.next = NULL;  
  
  node0.value = a[0];
  node1.value = a[1];
  node2.value = a[2];  
  node3.value = a[3];  
  
  // Link nodes
  InsertNode(&node0, &node1);
  InsertNode(&node1, &node2);
  InsertNode(&node2, &node3);
  
  // Print current list
  TransverseNode(&node0);
  
  // Nodes to add
  Node n1, n2, n3;
  n1.value = 'z';
  n2.value = 'x';
  n3.value = 'y';
  
  // Insert nodes
  InsertNode(&node0, &n1);
  InsertNode(&node1, &n2);
  InsertNode(&node2, &n3);
  
  //Print changed list
  TransverseNode(&node0);
  
}

void InsertNode(Node* curNode, Node* nextNode)
{
  nextNode->next = curNode->next;
  curNode->next = nextNode;
}
void TransverseNode(Node* node)
{
  while(node != NULL)
  {
    printf("%c", node->value);
    node = node->next;
  }
  printf("\n");
}