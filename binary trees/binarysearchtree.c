#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int num;
    struct Node* right;
    struct Node* left;
} Node;

// createing an binary TREE
Node* createTree(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> num = x;
    newNode -> right = NULL;
    newNode -> left = NULL;
    return newNode;
}
// insert in binary search tree

Node* insertNode(Node* root, int x){
    if(root == NULL){
       return createTree(x);
    }
    else if(root -> num < x){
        root -> right = insertNode(root -> right, x);
    }
    else if(root -> num > x){
        root -> left = insertNode(root -> left, x);
    }
    return root;
}

//traversal


// search 
bool search(Node* root, int x){
    if((root -> num == x) && (root != NULL)) return true;
    else if((root != NULL) && (root -> num > x)) search(root -> left, x);
    else if((root != NULL) && (root -> num < x)) search(root -> left, x);
    else return false;
}


// delete 


// printing 1.preorder 2.postorder
void preorder(Node* root){
    if(root != NULL){
        printf("%d\t", root -> num);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(Node* root){
    if(root != NULL){
        inorder(root -> left);
        printf("%d\t", root -> num);
        inorder(root -> right);
    }
}

void postorder(Node* root){
    if(root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        printf("%d\t", root -> num);
    }
}

bool isbst(Node* root){
    if(root == NULL){
        return true;
    }
    else if((root-> num < root -> right -> num) && (root -> num > root -> left -> num) ) 
        return (isbst(root->right) && isbst(root->left));
    else return false;
    
}

int main(){
    Node* root = NULL;
    int a[7] = {50,30,20,40,70,60,80};
    for(int i = 0; i < 7; i++) root = insertNode(root, a[i]);
    
    printf("\npreordered:\t");
    preorder(root);
    
    printf("\ninordered:\t");
    inorder(root);

    printf("\npostordered:\t");
    postorder(root);
    printf("\n");
    isbst(root)?printf("yes\n"):printf("no\n");
}
