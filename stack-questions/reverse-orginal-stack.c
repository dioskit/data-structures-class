#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* getNode(int x);

void push(Node** top, int x);

int pop(Node** top);

bool isempty(Node** top) {
    return *top == NULL;
}

void print(Node** top) {
    Node* temp = *top;
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseStack(Node** top) {
    Node* top1 = NULL;
    Node* top2 = NULL;

    while (!isempty(top))
        push(&top1, pop(top));
    printf("After first reversal:\n");
    print(&top1);
    
    while (!isempty(&top1))
        push(&top2, pop(&top1));
    printf("After second reversal:\n");
    print(&top2);

    while (!isempty(&top2))
        push(top, pop(&top2));
    printf("After final reversal:\n");
    print(top);

    free(top1);
    free(top2);
}

int main() {
    Node* top = NULL;
    // Push some elements onto the stack
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);

    printf("Original Stack:\n");
    print(&top);

    reverseStack(&top);

    return 0;
}


Node* getNode(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void push(Node** top, int x) {
    Node* newNode = getNode(x);
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    Node* temp = *top;
    *top = (*top)->next;
    int NUM = temp->data;
    free(temp);
    return NUM;
}

bool isempty(Node** top) {
    return *top == NULL;
}

void print(Node** top) {
    Node* temp = *top;
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseStack(Node** top) {
    Node* top1 = NULL;
    Node* top2 = NULL;

    while (!isempty(top))
        push(&top1, pop(top));
    printf("After first reversal:\n");
    print(&top1);
    
    while (!isempty(&top1))
        push(&top2, pop(&top1));
    printf("After second reversal:\n");
    print(&top2);

    while (!isempty(&top2))
        push(top, pop(&top2));
    printf("After final reversal:\n");
    print(top);

    free(top1);
    free(top2);
}