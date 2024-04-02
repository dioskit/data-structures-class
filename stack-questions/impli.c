#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int num;
    struct Node* next;
};
typedef struct Node Node;

Node* head = NULL;
Node* tail = NULL;

Node* getNode(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> num = x;
    newNode -> next = NULL;
    return newNode;
}

bool push(int x){
    bool sucess = false;
    Node* newNode = getNode(x);
    if(head == NULL){
        tail = newNode;
        head = newNode;
        sucess = true;
    }
    else{
        
    }
    
} 