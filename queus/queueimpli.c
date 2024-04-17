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

queue* Q;
void create_queue(queue*);
queue* insert(queue*, int);
queue* delete_element(queue*);
queue* display(queue*);
int peek(queue*);

int main(){
    int val, option;
    create_queue(Q);
    // clrscr();
    do{
        printf("\n*****MAIN MENU*****");
        printf("\n 1. INSESRT");
        printf("\n 2. DELETE\n 3. PEEK\n 4. EXIT\n Enter your option :");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("\n Enter the number to insert in the queue:");
                scanf("%d",&val);
                Q = delete_element(Q);
                break;
            case 2:
                Q = delete_element(Q);
                break;
            case 3:
                val = peek(Q);
                if(val != -1) printf("\n The valse at front of queue is: %d",val);
                break;
            case 4:
                Q = display(Q);
                break; 
        }
    }while(option != 5);
    getch();
    return 0;
}

void create_queue(queue* Q){
    Q -> rear = Q -> front = NULL;
}
queue* insert(queue* Q, int val){
    Node *ptr = (Node*)malloc(sizeof(Node));
    ptr -> data = val;
    if(Q -> front == NULL){
        Q -> front = ptr;
        Q -> rear = ptr;
        Q -> front -> next = Q -> rear -> next = NULL;
    }
    else{
        Q -> rear -> next = ptr;
        Q -> rear = ptr;
        Q -> rear -> next = NULL;
    }
    return Q;
}

queue* displiay(queue* Q){
    Node* ptr = Q -> front;
    if(ptr == NULL) printf("\n QUEUE IS EMPTY");
    else{
        printf("\n");
        while(ptr != Q -> rear){
            printf("%d\t", ptr -> data);
            ptr = ptr -> next;
        }
        printf("%d\n", ptr -> data);
    }
    return Q;
}

queue* delete_element(queue* Q){
    Node * ptr = Q -> front;
    if( Q -> front == NULL) printf("\n UNDERFLOW");
    else{
        Q -> front = Q -> front -> next;
        printf("\n The value beeing dleted is : %d", ptr -> data);
        free(ptr);
    }
    return Q;
}
int peek(queue* Q){
   if(Q -> front == NULL){
    printf("\n QUEUE IS EMPTY");
    return -1;
   }
   else return Q -> front -> data;
}