/*
tree
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};
typedef struct node node;

void insert(int, node*);
bool isbinary(node*);
bool isSubgreater(node*, int);
bool isSublesser(node*, int);

void inorder(node*);
int main(){
    node* root = NULL;
    for(int i = 0; i < 10; i++){
        root = insert(i, root),
        for(int j = i; j < i+5; j++) root = insert(j,root);
    }
    inorder(root);
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->right);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
bool isbinary(node* root){
    if(root == NULL) return true;
    if( 
        isSublesser(root-left, root->data)
        &&isSubgreater(root->right, root->data)
        &&isbinary(root->left)
        &&isbinary(root->right)    
    ) return true;
    else return false;
}
bool isSublesser(node* root, int value){
    if(root == NULL) return true;
    if(
        root ->data <=  value 
        && isSublesser(root->left,value)
        && isSublesser(root->right,value)  
    ) return true;
    else return false;
}
