#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
typedef struct Node Node;
Node *head = NULL;
 
void insert(int x);
void check(int x);
void print();
void dprint(Node *temp);

int main(){
    int a[] = {11,12,13,15,16,17};
    int length = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < length; i++)
        insert(a[i]);
    print();
    check(14);
    dprint(head);
}
 
void insert(int x){
    Node* newNode = (Node*)(malloc(sizeof(Node)));
    newNode -> data = x;
    newNode -> next = NULL;
    Node* temp = head;
    if(head == NULL) head = newNode;
    else{
        while(temp -> next != NULL) temp = temp ->next;
        temp -> next = newNode;
    }
}
void check(int x){
    Node *temp = head, *temp1 = head -> next;
    while(temp1 -> next != NULL){
        temp = temp -> next;
        temp1 = temp1 ->next;
        if(x < temp1 -> data && x > temp -> data){
            Node *newNode = (Node*)(malloc(sizeof(Node)));
            newNode -> data = x;
            newNode -> next = temp1;
            temp -> next = newNode;
        }
    } 
}
void print(){
    Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp ->data);
        temp = temp -> next;
    }
    printf("\n");
}
void dprint(Node *temp) {
    if (temp->next == NULL) {
        printf("%d ", temp->data);
        return;
    } else {
        dprint(temp->next);
        printf("%d ", temp->data);
    }
}