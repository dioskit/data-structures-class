#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
typedef struct Node Node;
Node *head = NULL;
Node* getNewNode(int x){
    Node* newNode = (Node*)(malloc(sizeof(Node)));
    newNode ->data = x;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}
void InsertAtEnd(int x){
    Node *new = getNewNode(x);
    if(head == NULL) head = new;
    else{
        Node * temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        new -> prev = temp;
        temp -> next = new;
    }
}
void InsertAtStart(int x){
     Node *new = getNewNode(x);
    if(head == NULL){
        head = new;
        return;
    }
    head -> prev = new;
    new -> next = head;
    head = new;
}
void InsertAtNth(int x, int position){
    Node * temp = getNewNode(x);
    
}
void print(){
    Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
int main(){
    for(int i = 10; i > 0; i--) InsertAtEnd(i);
    print();
    return 0;
}