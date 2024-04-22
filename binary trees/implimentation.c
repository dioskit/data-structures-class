#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;
Node* tree;
void create_tree(Node*);
Node* insertElement(Node*, int);
void preorderTraversal(Node*);
void inorderTraversal(Node*);
void postorderTraversal(Node*);
Node* findSmallestElement(Node*);
Node* deleteElement(Node*,int);
Node* mirrorImage(Node*);
int totalNodes(Node*);
int totalExternal(Node*);
int totalInternal(Node*);
int height(Node*);
Node* deleteTree(Node);

int main(){
    int option, val;
    Node* ptr;
    create_tree(tree);
    clrscr();
    do{
        printf("\n*********MAIN MENU********\n\n1. Insert Element\n 2. preorder traversal");
        printf("\n3. inorder traversal\n4. postorder traversal\n5. Find the smallest element\n6. find the largest element");
        printf("\n7. delete an element\n8. count the total number of nodes\n9. count the total number of internal nodes\n11. determine the height of the tree\n12. find the mirror image of the tree");
        printf("\n13. delete the tree");
        printf("\n14. EXIT");
        printf("\n\n enter your option : ");
        scnaf("%d", &option);
        switch(option){
            case 1:
                printf("\n enter the value of the new node: ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;
            case 2:
                printf("\n the elements of the tree are: \n");
                preorderTraversal(tree);
                break;
            case 3:
                printf("\n the elements of the tree are:\n");
                inorderTraversal(tree);
                break;
            case 4:
                printf("\n the elements of the tree are:\n");
                ptr = findSmallestElement(tree);
                break;

        }
    }
}