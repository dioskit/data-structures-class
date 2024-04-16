#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef strcut Node{
    int data;
    struct Node* next;
} Node;

Node * head = NULL;
Node* getNode(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}
void insert(int x){
    Node* newNode = getNode(x);
    newNode -> next = head;
    head = newNode;
}
void fixLoopedList() {
    if (head == NULL || head->next == NULL)
        return; 
    
    Node* fastNode = head;
    Node* slowNode = head;

    while (fastNode != NULL && fastNode->next != NULL) {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;

        if (slowNode == fastNode) {
            break;
        }
    }

    // If no loop is found, return
    if (slowNode != fastNode)
        return;

    // Move slowNode to head and advance both pointers at the same pace
    slowNode = head;
    while (slowNode->next != fastNode->next) {
        slowNode = slowNode->next;
        fastNode = fastNode->next;
    }

    // Now fastNode points to the last node of the loop
    fastNode->next = NULL;
    printf("Loop detected and fixed.\n");
}
