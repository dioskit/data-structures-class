/**
 * tower of hanoi / Sacred Tower of Brahma
 * using stacks
 * rules of game:
 *      - cant place bigger disc over smaller disc
 *      - one disc at a time 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;
// lets say we have three pillars [pillar one] [pillar two] [pillar three]
Node *pll1 = NULL;
Node *pll2 = NULL;
Node *pll3 = NULL;

void printPillar(){
    Node *temp = pll1;
    Node *temp2 = pll2;
    Node *temp3 = pll3;

    printf("pillar one: ");
    while(temp!=NULL){
        printf("%d ", temp -> next);
        temp = temp -> next;
    }
    printf("\npillar two: ");
    while(temp2!=NULL){
        printf("%d ", temp2 -> next);
        temp2 = temp2 -> next;
    }
    printf("\npillar three: ");
    while(temp3!=NULL){
        printf("%d ", temp3 -> next);
        temp3 = temp3 -> next;
    }
    printf("\n");
}
Node * getNode(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}
void initial(int noOfDisks, int fromPillar){
    switch(fromPillar){
        case 1:
        for(int i = 3; i < noOfDisks; i++){
            Node *temp = pll1;
            Node* newNode = getNode(i);
            newNode -> next = temp;
            
        }
        break;
        case 2:
        break;
        case 3:
        break;
    }
}


int main(){
    int noOfDisks;
    // only three pillars is valid for this game
    int fromPillar, toPillar;
    printf("enter number of disc: ");
    scanf("%d",&noOfDisks);
    printf("enter\n\t1 for first pillar\n\t2 for second pillar\n\t3 for third pillar\n");
    printf("enter initial pillar: ");
    scanf("%d",&fromPillar);
    printf("enter target pillar: ");
    scanf("%d",&toPillar);
    initial(noOfDisks,fromPillar);
    printPillar();
    return 0;
}