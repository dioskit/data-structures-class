  /*binary search tree
  in bst (balanced) search(x) = insert = remove = O(log(n)), 
  -> binary tree in which for each nodes n left subtree is lesser and values of al the nodes is the right is greater 
  
  */
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;
//useing malloc we get memory for this structure
//in linked list we keep head of linked list similarly we keep root node in bst
Node* getNewNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node* insert(Node *root, int data){
    if(root == NULL){
        root = getNewNode(data);
        return root;
    }
    else if(data <= root->data){
        root -> left = insert(root->left, data); 
    }
    else{
        root ->right = insert(root-> right, data);
    }
    return root;
}

bool search(Node *root, int data){
    if(root == NULL) return false;
    else if(root -> data ==  data) return true; 
    else if(data <= root->data) return search(root->left, data);
    else return search(root->right, data);
}

int main(){
    Node* root = NULL; //creating an empty tree
    insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    for(int i = 0; i < 15; i++) root = insert(root, i*(i+3));
    // int count = 0;
    // for(int j = 0; j < 100; j++){
    //     if(search(root, j)){
    //         printf("%d in BST\t\n",j);
    //         if(count%5 == 0){
    //             printf("\n");
    //             count++;
    //         } 
    //     }
    //     else{
    //         printf("%d not in BST\t\n",j);
    //         if(count%5 == 0){
    //             printf("\n");
    //             count++;
    //         } 
    //     } 
    // }
}