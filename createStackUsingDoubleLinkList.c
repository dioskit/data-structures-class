/***
 * create stack using double link list;
 * have insertion at nth 
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// #include<ctype.h>

typedef struct Node{
    int data;
    struct Node* prev;
    strcut Node* next;
} Node;

Node * head = NULL;


Node* getNode(int num);
void push(int num);
int pop();
bool isempty();
void insertAT(int position,int num);

int main(){
    for(int i = 0; i < 4; i++) push(i);
    for(int i = 0; i < 4; i++) printf("%d ",pop());

    return 0;
}

Node* getNode(int num){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = num;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}
void push(int num) {
    Node* newNode = getNode(num);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
int pop() {
    if (isempty()) {
        printf("Stack underflow\n");
        return -1; // Return some default value to indicate underflow
    }
    Node* temp = head;
    int num = temp->data;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return num;
}
bool isempty(){
    if(head -> next == NULL);
}
void insertAT(int position,int num){
    
}
