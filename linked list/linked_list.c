/*********************************************
 * 
 * this program is to 
 * insert at the begining, at some postion(1 as first positon) and at the end.
 * deletion at the begining, at some postion(1 as first positon) and at the end.
 * 
 * to additon of reverse is not added yet
 * 
************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;
Node* head = NULL;

//insert functions
void insert();
void insertB(int x);
void insertN(int x, int pos);
void insertE(int x);
//delete functions
void Delete();
void DeleteB();
void DeleteN(int pos);
void DeleteE();
//function to reverse the linked list
void reverse();
// function to print the linked list
void print();
// navagation menu and its options
void menu();
int option_insertion_or_deletion();

int main() {
    char yesNo;
    printf("do you want test case list with elements already inserted?\nenter (y/n):");
    scanf("%c",&yesNo);
    if(yesNo == 'Y' || yesNo == 'y'){
        for(int i = 0; i < 10; i++)
            insertB(i*7/3);
            
        printf("your list is: ");
        print();
        menu();
    }
    else menu();
    
    printf("<<<successfully exited>>>");
    return 0;
}

void insert() {
    bool invalid = false;
    int insert_type;
    int insert_element, insert_pos;
    printf("enter element: ");
    scanf(" %d", &insert_element);
    printf("where do you want to insert:\n\t1. beginning\n\t2. at some position\n\t3. at the end\n\tENTER: ");
    scanf(" %d", &insert_type);

    switch (insert_type) {
        case 1:
            insertB(insert_element);
            break;
        case 2:
            int position;
            printf("enter the position: ");
            scanf(" %d", &position);
            insertN(insert_element, position);
            break;
        case 3:
            insertE(insert_element);
            break;
        default:
            invalid = true;
            printf("error. invalid input\n");
            break;
    }
    if (!invalid) {
        printf("list after inserting: \n");
        print();
    }
}

void insertB(int x) {
    Node* newNode = (Node*)(malloc(sizeof(Node)));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void insertN(int x, int pos){
    Node* newNode = (Node*)(malloc(sizeof(Node)));
    newNode->data = x;
    if (pos == 1) {
        insertB(x);
    } else {
        Node* temp = head, *temp1 = head->next;
        for (int i = 0; i < pos - 2; i++) {
            temp = temp->next;
            temp1 = temp1->next;
        }
        temp->next = newNode;
        newNode->next = temp1;
    }
}

void insertE(int x) {
    Node* newNode = (Node*)(malloc(sizeof(Node)));
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void Delete() {
    bool invalid = false;
    int delete_position, delete_choice;
    printf("where do you want to delete:\n\t1. beginning\n\t2. at some position\n\t3. at the end\n\tENTER: ");
    scanf(" %d", &delete_choice);
    switch (delete_choice) {
        case 1:
            DeleteB();
            break;
        case 2:
            printf("enter the position:");
            scanf(" %d", &delete_position);
            DeleteN(delete_position);
            break;
        case 3:
            DeleteE();
            break;
        default:
            printf("Error invalid input");
            invalid = true;
            break;
    }
    if (!invalid) {
        printf("after deletion list is:\n ");
        print();
    }
}

void DeleteB() {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

void DeleteN(int pos) {
    if (pos == 1) DeleteB();
    else {
        Node* temp = head, *temp1 = head->next;
        for (int i = 0; i < pos - 2; i++) {
            temp = temp->next;
            temp1 = temp1->next;
        }
        if (temp1 != NULL) {
            temp->next = temp1->next;
            free(temp1);
        }
    }
}

void DeleteE() {
    if (head != NULL) {
        Node* temp = head, *temp1 = head->next;
        while (temp->next != NULL && temp->next->next != NULL) {
            temp = temp->next;
            temp1 = temp1->next;
        }
        if (temp1 != NULL) {
            temp->next = NULL;
            free(temp1);
        }
    }
}

void reverse(){
    if(head == NULL) return;
    else{
        Node* current = head;
        Node* prev = NULL, * after = head -> next;
        while(current -> next != NULL){
            current -> next = prev;
            prev = current;
            current = after;
            after = after -> next;
        }
        current -> next = prev;
        head = current;
    }
}

void print() {
    printf("--->>> ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void menu() {
    switch (option_insertion_or_deletion()) {
        case 1:
            insert();
            menu();
            break;
        case 2:
            Delete();
            menu();
            break;
        case 3:
            reverse();
            printf("your list after reversal: ");
            print();
            menu();
            break;
        case -1:
            printf("exiting menu\n");
            break;
        default:
            printf("Error.. invalid input\n");
            menu();
            break;
    }
    
}

int option_insertion_or_deletion() {
    int choice;
    printf("\n---ENTER---\n\t1. for insertion\n\t2. for deletion\n\t3. for reverse\n\t-1. to exit\n\tenter: ");
    scanf(" %d", &choice);
    return choice;
}
