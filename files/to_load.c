#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
typedef struct Node Node;
Node * head = NULL;

void insert(int x);
void print();

int main(){
    int random_number;
    for(int i = 0; i < 10; i++){
        srand(i);
        random_number = rand() % 100 + 1;
        insert(random_number);
    }
    print();
    return 0;
}

void insert(int x){
    Node * newNode = (Node*)(malloc(sizeof(Node)));
    newNode -> data = x;
    newNode -> next = NULL;
    if(head == NULL) head = newNode;
    else{
        Node * temp = head;
        while(temp -> next != NULL) temp = temp -> next;
        temp -> next = newNode;
    }
}
void print(){
    Node * temp = head;
    while(temp  != NULL){
        printf("data[%d]\tlink[%d]\n",temp ->data, temp ->next);
        temp = temp -> next;
    }
    printf("\n");
}