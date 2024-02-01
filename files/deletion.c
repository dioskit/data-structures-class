#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;

Node *head; //global
// 1st fix the link
// free the space
void insert(int data);      //insert an integer at end of list 
void print();               //print all elements in the list
void Delete(int n);          // delete node at positon n
int man(){
    int arr[5] = {11,2,3,4,46};
    for(int i = 0; i < 5; i++){
        insert(arr[i]);
    }
    printf("your list is: ");
    print();
    int del_el;
    printf("which element you want to delete:");
    scanf("%d",&del_el);
    Delete(del_el);
    print();
    
}
void insert(int data){
    Node *newNode = (Node*)(malloc(sizeof(Node)));
    Node *temp = head;
    newNode -> data = data;
    newNode -> next = NULL;
    if(head == NULL) head = newNode;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}
void print(){
    Node *temp = head;
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp->next;
    }
    printf("\n");
}
void Delete(int n){
    Node *temp = head;
    //   1    2   3   4   5   6    7   8
    //   n0  n1  n2  n3  n4  n5   n6  n7
    //  [1] [1] [1] [1] [1] [1] [1] [1]  we want 5th to delete
    //               |   |-> n-1 is to be deleted
    //               temp to be here
    // temp2 = temp -> next
    // so that temp -> next =  temp2 -> next 
    // free(temp2)
    if(n == 1){
        head = temp -> next;
        free(temp);
        return;
    }
    
    for(int i = 0 ; i < n-2; i++)
        temp = temp->next;
        
    Node *temp2 = temp -> next;
    temp -> next = temp2 -> next;
    free(temp2);
} 










