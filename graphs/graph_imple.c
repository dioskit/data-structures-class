/************
 *program to to create a graph of n vertices usign an adjacency list.
 *
 * also write the code to read and print its information and fnally to delete the graph. 
 * 
*************/

#include <stdio.h>
#include< conio.h>
#include<alloc.h>

typedef struct node{
    char vertex;
    struct node *next;
} node;
struct node *gnode;
void displayGraph(node *adj[], int no_of_nodes);
void deleteGraph(node *adj[], int no_of_nodes);
void createGraph(node *adj[], int no_of_nodes);

int main{
    node *Adj[10];
    int i, no_of_nodes;
    clrscr();

    printf("\nEnter the number of npdes in G: ");
    scanf("%d",&no_of_nodes);
    for(int i = 0; i < no_of_nodes; i++)
        Adj[i] = NULL;
    createGraph(Adj, no_of_nodes);
    displaygraph(Afj, no_of_nodes);
    deleteGraph(Adj, no_of_nodes);
    getch();
    return 0;
}

void createGraph(node *adj[], int no_of_nodes){
    node *new_node, *last;
    int i, j, n, val;
    for(i = 0; i < no_of_nodes; i++){
        last = NULL;
        printf("\n Enter the number of neighbours of %d: ",i);
        scanf("%d", &n);
        for(j = 1; j <= n; j++){
            printf("\n Enter the neighbour %d of %d: ", j, i);
            scanf("%d", val);
            new_node -> vertex = val;
            new_node -> next = NULL;
            if(Adj[i] == NULL)
                Adj[i] = new_node;
            else
                last -> next = new_node;
            last = new_node;  
        }

    }

}

void displayGraph(node *adj[], int no_of_nodes){
    node *ptr;
    for(int i = 0; i < no_of_nodes; i++){
        prt = Adj[i];
        pritnf("\n The neighbours of Node %d are: ",i);
        while(ptr != NULL){
            printf("\t%d", ptr -> vertex);
            ptr = ptr -> next;
        }
    }
}
void deleteGraph(node *adj[], int no_of_nodes){
    node *temp, *ptr;
    for(int i = 0; i <= no_of_nodes; i++){
        ptr = Adj[i];
        while(ptr != NULL){
            temp = ptr;
            ptr = ptr -> next;
            free(temp);
        }
        Adj[i] =NULL;
    }
}




