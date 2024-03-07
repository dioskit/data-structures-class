/****
 * create a stack to solve tower of hanoi
 * 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;
// functions
Node* getNode(int x);
void push(int x, Node*head);
int pop(Node** head);

// function to construct initial pillar

// funcction to print each pillar

int main(){
    Node * pillar1 = NULL;
    Node * pillar2 = NULL;
    Node * pillar3 = NULL;
    push(5,&pillar1);
    push(5,&pillar1);
    push(5,&pillar1);
}

Node* getNode(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}
void push(int x, Node **head){
    Node* newNode = getNode(x);
    newNode -> next = head;
    head = newNode;
}
int pop(Node** head){  
    if(*head == NULL) return;
    Node * temp = *head;
    int x = *temp -> data;
    **head = *temp -> next;
    free(*temp);
    return x;
}
