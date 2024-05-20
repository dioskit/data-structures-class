#include<stdio.h>
#include<stdlib.h>

// Node structure for adjacency list
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create an adjacency list representation of a graph
void createGraph(Node* Adj[], int no_of_nodes) {
    for (int i = 0; i < no_of_nodes; i++) {
        Adj[i] = NULL;  // Initialize adjacency list for each vertex
    }

    for (int i = 0; i < no_of_nodes; i++) {
        Node* last = NULL;
        int n;
        printf("Enter the number of neighbors of vertex %d: ", i);
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int neighbor;
            printf("Enter neighbor %d of vertex %d: ", j + 1, i);
            scanf("%d", &neighbor);
            Node* new_node = createNode(neighbor);  // Create a new node for the neighbor
            if (Adj[i] == NULL) {
                Adj[i] = new_node;  // First neighbor in the list
            } else {
                last->next = new_node;  // Append the neighbor to the end of the list
            }
            last = new_node;
        }
    }
}

// Function to traverse the adjacency list representation of a graph
void traverseGraph(Node* Adj[], int no_of_nodes) {
    for (int i = 0; i < no_of_nodes; i++) {
        printf("Adjacent nodes of vertex %d: ", i);
        Node* current = Adj[i];
        while (current != NULL) {
            printf("%d ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int no_of_nodes;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &no_of_nodes);

    Node* Adj[no_of_nodes];  // Array of pointers to linked lists
    createGraph(Adj, no_of_nodes);

    printf("\nAdjacency list representation of the graph:\n");
    traverseGraph(Adj, no_of_nodes);

    // Free memory allocated for nodes
    for (int i = 0; i < no_of_nodes; i++) {
        Node* current = Adj[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}
