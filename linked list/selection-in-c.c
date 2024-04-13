#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node * next;
};
typedef struct Node Node;
Node * head = NULL;
void insert(int x){
    Node * newNode = (Node*)(malloc(sizeof(Node)));
    newNode -> next = NULL;
    newNode -> data = x;
    
}

