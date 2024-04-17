#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node* next;
};

struct queue{
    struct Node* front;
    struct Node* rear;
};
typedef struct Node Node;
typedef struct queue queue;

queue *Q;
void create_queue(queue*);
queue* insert(queue*, int);
queue* delete_element(queue*);
queue* display(queue*);
int peek(queue*);

void create_queue(queue*);
queue* insert(queue*, int);
queue* delete_element(queue*);
queue* display(queue*);
int peek(queue*);