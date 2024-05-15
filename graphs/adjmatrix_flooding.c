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

// Function to perform flooding algorithm
void floodingAlgorithm(int adjMatrix[][MAX_NODES], int no_of_nodes, int source) {
    int i, j;
    printf("\nFlooding Algorithm from vertex %d:\n", source);
    for (i = 0; i < no_of_nodes; i++) {
        if (adjMatrix[source][i] == 1 && i != source) {
            printf("Packet sent from vertex %d to vertex %d\n", source, i);
            // Flooding to all neighbors of vertex source except source itself
            for (j = 0; j < no_of_nodes; j++) {
                if (j != source && adjMatrix[i][j] == 1) {
                    printf("Packet forwarded from vertex %d to vertex %d\n", i, j);
                }
            }
        }
    }
}

int main() {
    int no_of_nodes, source;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &no_of_nodes);

    int adjMatrix[MAX_NODES][MAX_NODES];
    createAdjacencyMatrix(adjMatrix, no_of_nodes);

    printf("Enter the source vertex for flooding: ");
    scanf("%d", &source);

    floodingAlgorithm(adjMatrix, no_of_nodes, source);

    return 0;
}
