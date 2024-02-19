#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct Node{
    int data;
    struct Node * next;
};
typedef struct Node Node;
Node * head = NULL;

void swap(Node *a, Node*b);
void insert(int x);
void print();
int maxN();
void bsort();
int main(){
    int random_number;
    for(int i = 10; i > 0; i--){
        srand(i);
        random_number = rand() % 100 + 1;
        insert( random_number);
    }
    
    print();
    bsort();
    print();
    int m = maxN();
    printf("%d is the max\n",m);
    return 0;
}

void swap(Node *a, Node *b){
    int var = a -> data;
    a -> data = b -> data;
    b -> data = var;
}
void bsort(){
    Node *temp = head, *last = NULL;
    if(temp == NULL) return;
    bool swapped ;
    do{
        swapped = false;
        temp = head;
        while(temp -> next != last){
            if(temp -> data > temp -> next -> data){
                swap(temp, temp -> next);
                swapped = true;
            }
            temp = temp -> next;
        }
        last = temp;
    }while(swapped);

}

int maxN(){
    if(head == NULL) return;
    else{
        Node *temp = head;
        int maxn = temp -> data;
        while(temp != NULL){
            if((temp -> data) > maxn ) maxn = temp -> data;
            temp = temp -> next;
        }
        return maxn;
    }
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
        printf("%d ",temp ->data);
        temp = temp -> next;
    }
    printf("\n");
}