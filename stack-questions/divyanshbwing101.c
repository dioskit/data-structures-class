/********************************
 * write a function hanoi(n, start, end) 
 * n is number of disk
 * start is start rod
 * end is end rod
 * assumptions
 * 1 <= start <= 3
 * 1 <= end <= 3
 * start != end
 * n >= 1
 * 
 * 
 * pm(start, end) := print(start,->,end)
***************************************/





#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
typedef struct node Node;
Node * rod_one = NULL; 
Node * rod_two = NULL; 
Node * rod_three = NULL; 

void pm(Node* start, Node* end){
    while(start != NULL || end != NULL){
        printf("%d to %d",start -> data, end -> data);
        start = start -> next;
        end  = end -> next;
    }
    printf("\n");
}

void hanoi(int n, Node *start, Node*end){
    if(n == 1){
        pm(start,end)
    }
}


int main(){
    
}