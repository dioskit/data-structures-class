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
Node* findLargestElement(Node*);
Node* deleteElement(Node*,int);
Node* mirrorImage(Node*);
int totalNodes(Node*);
int totalExternal(Node*);
int totalInternal(Node*);
int height(Node*);
Node* deleteTree(Node*);

int main(void){
    int option, val;
    Node* ptr;
    create_tree(tree);
    // clrscr();
    do{
        printf("\n*********MAIN MENU********\n\n1. Insert Element\n2. preorder traversal");
        printf("\n3. inorder traversal\n4. postorder traversal\n5. Find the smallest element\n6. find the largest element");
        printf("\n7. delete an element\n8. count the total number of nodes\n9. count the total number of internal nodes\n11. determine the height of the tree\n12. find the mirror image of the tree");
        printf("\n13. delete the tree");
        printf("\n14. EXIT");
        printf("\n\n enter your option : ");
        scanf("%d", &option);
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
                postorderTraversal(tree);
                break;
            case 5:
                ptr = findSmallestElement(tree) ;
                printf("\n Smallest element is: %d",ptr -> data);
                break;
            case 6:
                ptr = findLargestElement(tree);
                printf("\n Largest element is : %d",ptr -> data) ;
                break;
            case 7:
                printf("\n ENter the element to be deleted");
                scanf("%d",&val);
                tree = deleteElement(tree,val);
                break;
            case 8:
                printf("\n total no. of nodes = %d",totalNodes(tree));
                break;
            case 9:
                printf("\n total no of external Nodes = %d", totalExternal(tree));
                break;
            case 10:
                printf("\n total no. of internal nodes = %d", totalInternal(tree));
                break;
            case 11:
                printf("\n the height of the tree = %d", height(tree));
                break;
            case 12:
                tree = mirrorImage(tree);
                break;
            case 13:
                tree = deleteTree(tree);
                break;
        }
    }while(option != 14);
    getch();
    return 0;
}

void create_tree(Node* tree){
    tree = NULL;
}

Node* insertElement(Node* tree, int val){
    Node *ptr, *nodeptr, *parentptr;
    ptr = (Node*)malloc(sizeof(Node));
    ptr -> data = val;
    ptr -> left = NULL;
    ptr -> right = NULL;
    if(tree == NULL){
        tree = ptr;
        tree -> left = NULL;
        tree -> right = NULL;
    }
    else {
        parentptr = NULL;
        nodeptr = tree;
        while(nodeptr!=NULL){
            parentptr=nodeptr;
            if(val < nodeptr ->data) nodeptr = nodeptr-> left;
            else nodeptr=nodeptr->right;
        }
        if(val<parentptr->data) parentptr -> left = ptr;
        else parentptr -> right = ptr;
    }
    return tree;
}

void preorderTraversal(Node* tree){
    if(tree!=NULL){
        preorderTraversal(tree->left);
       preorderTraversal(tree->right);
        printf("%d\t",tree->data);
    }
}

void inorderTraversal(Node* tree){
    if(tree!=NULL){
        inorderTraversal(tree->left);
        printf("%d\t",tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(Node*tree){
    if(tree!= NULL){
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t",tree->data);
    }
}

Node* findSmallestElement(Node* tree){
    if(tree == NULL || (tree->left == NULL)) return tree;
    else return findSmallestElement(tree->left);
}

Node* findLargestElement(Node* tree){
    if(tree == NULL || (tree->right == NULL)) return tree;
    else findLargestElement(tree->right); 
}

Node* deleteElement(Node* tree,int val){
    Node *cur, *parent, *suc, *psuc, *ptr;
    if(tree->left == NULL){
        printf("\n The tree is empty");
        return tree;
    }
    parent = tree;
    cur = tree->left;
    while(cur!=NULL && val!=cur->data){
        parent = cur;
        cur = (val < cur->data)? cur->left: cur->right;
    }
    if(cur == NULL){
        printf("\n the value to be deleted is not present in the tree");
        return(tree);
    }
    if(cur->left == NULL) ptr = cur->right;
    else if(cur->right == NULL) ptr = cur -> left;
    else{
        //find the in-order sucessor and its parent
        psuc = cur;
        cur = cur->left;
        while(suc->left!=NULL){
            psuc = suc;
            suc = suc->left;
        }
        if(cur == psuc){
            //situation 1
            suc -> left = cur->right;
        }
        else{
            //situation 2
            suc->left = cur->left;
            psuc->left = suc->right;
            suc->right = cur->right;
        }
        ptr = suc;
    }
    // attact ptr to the parent node
    if(parent->left == cur)
        parent->left = ptr;
    else
        parent->left = ptr;
    free(cur);
    return tree;
}

int totalNodes(Node* tree){
    if(tree == NULL)
        return 0;
    else
        return(totalNodes(tree->left) + totalNodes(tree->right) + 1);
}

int totalExternal(Node* tree){
    if((tree==NULL)||((tree->left==NULL) && (tree->right==NULL)))
        return 0;
    else
        return(totalInternal(tree->left)+totalInternal(tree->right)+1);
}

int totalInternal(Node* tree){
    if((tree==NULL)||((tree->left==NULL)&&(tree->right==NULL)))
        return 0;
    else
        return (totalInternal(tree->left)+totalInternal(tree->right)+1);
}

int height(Node* tree){
    int leftheight, rightheight;
    if(tree==NULL) return 0;
    else{
        leftheight = height(tree->left);
        rightheight = height(tree->right);
        if(leftheight > rightheight)
            return (leftheight + 1);
        else
            return (rightheight + 1);
    }
}

Node* mirrorImage(Node* tree){
    struct Node* ptr;
    if(tree!=NULL){
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        ptr = tree->left;
        ptr->left = ptr->right;
        tree->right = ptr;
    }
}

Node* deleteTree(Node* tree){
    if(tree!=NULL){
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}

