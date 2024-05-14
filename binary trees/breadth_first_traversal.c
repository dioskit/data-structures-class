#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSIZE 100

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;

//QUEUE  FUNCTIONS
node* queue[MAXSIZE];
int front = -1;
int rear = -1;
void enqueue(node*);
void dequeue();
bool isempty();
//tree functions
void inorder(node* root);
void levelOrder(node* root);
node* insert(int,node*);

int main(){
    node* root = NULL;
    for(int i = 10; i < 15; i++ ) root = insert(i,root);
    for(int j = 5; j < 10; j++) root = insert(j,root);
    // inorder(root);
    levelOrder(root);
}
// lever order challanges
void levelOrder(node* root){
    if(root==NULL) return;
    enqueue(root);
    while(!isempty()){
        node* current = queue[front];
        printf("%d ",current->data);
        if(current->left != NULL) enqueue(current->left);
        if(current->right != NULL) enqueue(current->right);
        dequeue(); //removing at front
    }
}
// tree creation functions
node* insert(int x, node* root){
    if(root == NULL){
        node* new = (node*)malloc(sizeof(node));
        new->data=x;
        new->right = new->left = NULL;
        root = new;
    }
    else if(x < root->data) root->left = insert(x,root->left);
    else root->right = insert(x,root->right);
    return root;
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

//queue options
void enqueue(node* root){
    if(((rear+1)%MAXSIZE) == front) return;
    else if(isempty()) front = rear = 0;
    else rear = (rear+1)%MAXSIZE;
    queue[rear] = root;
}
void dequeue(){
    if(isempty()) return;
    else if(front == rear) front = rear = -1;
    else front = (front+1)%MAXSIZE;
}
bool isempty(){
    if(front == -1 && rear == -1) return true;
    else return false;
}

