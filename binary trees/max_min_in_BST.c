
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// node allocation of memory form heap
Node* getNode(int data){
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->right = new->left = NULL;
    return new;
}
// inserting of the node
Node* insert(Node* root, int data){
    if(root == NULL){
        root = getNode(data);
        return root;
    }
    else if(data <= root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}
//   w the function th recurssively returns minimum number
int mini(Node* root){
    if(root->left == NULL) return root->data;
    else return mini(root->left);
}
//wrapper function for better ease in implementation
int min(Node* root){
    if(root == NULL){
        printf("empty tree\n");
        return -1;
    }
    else
        return mini(root);
} 
//Function that returns mazimum of BST
int maxi(Node* root){
    if(root->right == NULL) return root->data;
    else return maxi(root->right);
}
//wrapper funtction for maximum in BST
int max(Node* root){
    if(root == NULL){
        printf("empty tree\n");
        return -1;
    }
    else return maxi(root);
}
int main() {
    // initilaizing the root node if the BST
    Node* root = NULL;
    for(int i = 10; i < 100; i++) root = insert(root,(i*9)+(i/7));
    
    int m = min(root),M = max(root);
    printf("%d is the minimum\n%d is the maximum\n", m,M);
    return 0;
}








