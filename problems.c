/*****************************************************
 * 
 * Q1 detection of loop in singly linked list break the loop 
 * Q2 impelment stack using ary and linked list 
 * Q3 implement two stacks on the same arry [use both ends]
 * Q4 reverse a orginal stack using two temp stack
 * Q5 solve problem of tower of hanoi
 * 
 * tsewang stanzin 
 * ****************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
Node* getNode(int x);
void insert(int x);
void print();
void islooped();


int main(){
    for(int i = 14; i < 32; i--) insert(i);
    print();
    islooped();
    return 0;
}

Node* getNode(int x){
    Node* newNode =(Node*)malloc(sizeof(Node));
    newNode ->data = x;
    newNode ->next = NULL;
}
void insert(int x){
    Node* newNode = getNode(x);
    newNode ->next = head;
    head = newNode;
}
void print(){
    Node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp ->data);
        temp = temp -> next;
    }
}
void islooped(){
    bool isloop = false;
    Node* temp = head;
    Node* temp1 = head;
    while(temp != NULL){
        temp1 = temp -> next -> next;
        temp = temp -> next;
        if(temp1 == temp){
            isloop = true;
            break;
        }
    }
    temp = temp -> next;
    if(islooped)
    while(temp != temp1)
        temp = temp -> next;

    temp -> next = NULL;
}






