#include <stdio.h>

#define MAX_NODES 100

// Function to create an adjacency matrix representation of a graph
void createAdjacencyMatrix(int adjMatrix[][MAX_NODES], int no_of_nodes) {
    int i, j, n;
    for (i = 0; i < no_of_nodes; i++) {
        for (j = 0; j < no_of_nodes; j++) {
            adjMatrix[i][j] = 0;  // Initialize all elements to 0
        }
    }

    for (i = 0; i < no_of_nodes; i++) {
        printf("Enter the number of neighbors of vertex %d: ", i);
        scanf("%d", &n);
        printf("Enter the neighbors of vertex %d: ", i);
        for (j = 0; j < n; j++) {
            int neighbor;
            scanf("%d", &neighbor);
            adjMatrix[i][neighbor] = 1;  // Mark the edge between vertices i and neighbor
        }
    }
}

// Function to print the adjacency matrix
void printAdjacencyMatrix(int adjMatrix[][MAX_NODES], int no_of_nodes) {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < no_of_nodes; i++) {
        for (j = 0; j < no_of_nodes; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int no_of_nodes;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &no_of_nodes);

    int adjMatrix[MAX_NODES][MAX_NODES];
    createAdjacencyMatrix(adjMatrix, no_of_nodes);

    printAdjacencyMatrix(adjMatrix, no_of_nodes);

    return 0;
}
