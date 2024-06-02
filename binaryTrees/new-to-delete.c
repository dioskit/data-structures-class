#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} node;

node* getNew(int x){
    node* new = (node*)malloc(sizeof(node));
    new -> data = x;
    new -> right = new -> left = NULL;
    return new;
}

node* insert(int x, node* root){
    if(root == NULL){
        root = getNew(x);
        return root;
    }
    else if(root -> data > x) root -> left = insert(x, root->left);
    else if(root -> data < x) root -> right = insert(x, root->right);
    return root;
}

void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
        return;
    }
}

void postorder(node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

void preorder(node* root){
    if(root != NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int totalNodes(node* root){
    if(root == NULL) return 0;
    else return (totalNodes(root->left)+totalNodes(root->right) + 1);
}

int MAX(int a, int b){
    if(a>b)return a;
    return b;
}
        
int treeHeight(node* root){
    int leftHeight=0, rightHeight=0;
    if(root == NULL) return -1;
    leftHeight = treeHeight(root->left);
    rightHeight = treeHeight(root->right);
    return MAX(leftHeight,rightHeight)+1;
}

void describe(node* root){
    printf("TOTAL NUMBERS OF NODES ARE: %d",    totalNodes(root));
    printf("\nHEIGHT OF TREE IS: %d",treeHeight(root));
    printf("\n----ORDERS-----\n");
    printf("INORDER:\n\t");
    inorder(root);
    printf("\n");
    printf("POSTORDER:\n\t");
    postorder(root);
    printf("\n");
    printf("PREORDER:\n\t");
    preorder(root);
    return;
}

int main(){
    node* root = NULL;
    for(int j = 10; j < 15; j++) root = insert(j, root);
    for(int i = 0;  i < 5; i++) root = insert(i, root);
    describe(root);
    return -1;
}










