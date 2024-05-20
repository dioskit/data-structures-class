#include<stdio.h>
#include<stdlib.h>
#include<stdbool>

#define MAX_SIZE 100

typedef struct Edge{
    char *startVertex;
    char * endVertex;
    int weight;
} edge;
char vertex_list[MAX_SIZE];
char edge_list[max_size];