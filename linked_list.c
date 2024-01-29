#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;

Node *head = NULL;

void appendEnd(int x);
void printList();
void appendBeg(int x);
void appendNth(int x, int n);
void menu();
int main(){
    /*int arr[10] = {8,6,5,3,2,1,4,7,0,9};
    
    for(int i = 0; i < 10; i++){
        appendEnd(arr[i]);
    }
    printList();
    
    //checking working of appending at the beging
    int arr2[5] = {12,15,19,16,-5};
    for(int i = 0; i < 5; i++){
        appendBeg(arr2[i]);
    }
    printList();
    
    appendNth(-14,7);
    printList();*/
    menu();
    return 0;
    
}

void appendEnd(int x){
    Node *newNode = (Node*)(malloc(sizeof(Node)));
    newNode -> data = x;
    newNode -> next = NULL;
    if(head == NULL) head = newNode;
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void printList(){
    Node *temp = head;
    if(head == NULL) printf("empty list:");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void appendBeg(int x){
    //at the begining
    Node *newNode = (Node*)(malloc(sizeof(Node)));
    newNode -> data = x;
    newNode -> next = head;
    head = newNode;
}
void appendNth(int x, int n){
    Node *newNode = (Node*)(malloc(sizeof(Node)));
    newNode -> data = x;
    newNode -> next = NULL;
    Node *temp = head;
    if(n == 1){
        newNode -> next = head;
        head = newNode;
    }
    for(int i = 0; i < n-2; i++){
        temp = temp -> next;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}
void menu(){
    printf("--------MENU--------\n");
    printf("enter the option for element insertion:\n\t\t1 for insertion at the bigining\n\t\t2 for inserton a nth psotion\n\t\t3 for insertion end\n\t\t4for EXIT\n\t\tEnter options: ");
    int option,element,postion;
    scanf("%d", &option);
    switch(option){
        case 1:
            int n;
            printf("enter the number of elements to enter: ");
            scanf("%d",&n);
            for(int i = 0; i < n; i++){
                printf("enter element: ");
                scanf("%d",&element);
                appendBeg(element);
            }
            printList();
            menu();
            break;
        case 2:
            int in;
            printf("enter the number of elements to enter: ");
            scanf("%d",&in);
            for(int i = 0; i < in; i++){
                printf("enter element: ");
                scanf("%d",&element);
                printf("enter the postion: ");
                scanf("%d",&postion);
                appendNth(element,postion);
            }
            printList();
            menu();
            break;
        case 3:
            int ni;
            printf("enter the number of elements to enter: ");
            scanf("%d",&ni);
            for(int i = 0; i < ni; i++){
                scanf("%d",&element);
                appendEnd(element);
            }
            printList();
            menu();
            break;
        case 4:
            printList();
            printf("this is the list\nEXITING");
            break;
        default:
            printf("invalid input.\n");
            menu();
            break;
    }

}