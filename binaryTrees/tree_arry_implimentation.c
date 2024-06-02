#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node *createTree(int x){
    Node* tree = (Node*)malloc(sizeof(Node));
    tree ->key = x;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

// inserting into the tree
Node* insertNode(Node* root,int x){
    if(root == NULL) return createTree(x);
    else if(root -> key < x) root -> right = insertNode(root->right,x);
    else if(root -> key > x) root -> left = insertNode(root -> left, x);
    else return root;
}

bool search(Node* root, int x){
    if(root -> key == x && root != NULL) return true;

}
