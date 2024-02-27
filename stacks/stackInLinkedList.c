#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node* next;
};
typedef struct Node Node;
Node * top = NULL;
void push(char x){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> data = x;
    temp -> next = top;
    top = temp;
}
void pop(){
    Node* temp;
    if(top == NULL) return;
    temp = top;
    top = top -> next;
    free(temp);
}
void print(){
    Node * temp = top;
    while (temp != NULL){
        printf("%c",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
    
}
// reversal of string using stack and linked list
int main(){
    char string[] = "hello";
    print();
    for(int i = 0; string[i] != '\0'; i++) push(string[i]);
    print();
    return 0;
}