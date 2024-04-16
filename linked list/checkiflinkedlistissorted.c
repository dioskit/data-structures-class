#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;
Node* head = NULL;

Node* getNode(int x);
void insert(int x);
bool checkOrder();
bool isempty(){
    return head == NULL;
}
void print(){
    Node* temp = head;
    if(isempty()) return;
    else while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}

int main(){
    int arr[5] = {1,20,3,4,5};
    for(int i = 0; i < 5; i++) insert(arr[i]);
    print();
    checkOrder()?printf("correct order\n"):printf("not sorted\n");
    print();
}

Node* getNode(int x){
    Node* new = (Node*)malloc(sizeof(Node));
    new -> data = x;
    new -> next = NULL;
    return new;
}

void insert(int x){
    Node* newNode = getNode(x);
    if(head == NULL) head = newNode;
    else{
        Node* temp = head;
        while(temp -> next != NULL) temp = temp -> next;
        temp -> next = newNode;
    }
}

bool checkOrder(){
    Node* temp = head;
    if(head == NULL) printf("empty\n");
    else {
        while(temp -> next != NULL){
            if((temp -> data) >  (temp -> next -> data)) return false;
            temp = temp -> next;
        }
    }
    return true;
}


