#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

//stack in linked
typedef struct Node{
    int data;
    struct Node* next;
} Node;
Node * head = NULL;

void push(int x);
Node* pop();
void print();

//stack using arry
int stack[MAX_SIZE];
int top = -1;

void push_(int x);
int pop_();
int print_();

int main(){
    for(int i = 0; i < 10; i++) push(i+3);
    print();
    Node* a = pop();
    printf("%d is popped from the linked list: \n",a -> data);
    print();
    while(a -> next != NULL){
        a = pop();
        printf("%d is popped from the linked list:\n",a -> data);
        free(a);
    }

    for(int i = 5; i < 15; i++) push_(i*7);
    print_();
    int number;
    do{
        number = pop_();
        printf("%d is popped from stack\n",number);
    }while(top != -1);
    return 0;
}

void push(int x){
    Node * newNode = (Node*)(malloc(sizeof(Node)));
    newNode -> data = x;
    newNode -> next = head;
    head = newNode;
}
Node* pop(){
    if(head == NULL) return NULL;
    else{
        Node *temp = head;
        int num = head -> data;
        head = head -> next;
        return temp;
    }
}
void print(){
    Node * temp = head;
    while(temp != NULL){
        printf("%d -> ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void push_(int x){
    top++;
    stack[top] = x;
}
int pop_(){
    int result = stack[top];
    top--;
    return result;
}
int print_(){
    int temp = top;
    while(temp != -1){
        printf("%d ",stack[temp]);
        temp--;
    }
    printf("\n");
}
