# ``GRAPHS``

## DEFINATION

A graph G is defined as an ordered set (V, E), where V(G) represents the set of 
vertices and E(G) represents the edges that connect these vertices.

    [A]-- [B] -- [C]
     |   /   \    / 
     |  /     \  /
    [D]--------[E]


 Figure shows a graph with V(G) = {A, B, C, D and E} and E(G) = {(A, B), (B, C),  
(A, D), (B, D), (D, E), (C, E)}. 

Note that there are five vertices or nodes and six 
edges in the graph.


## TERMINOLOGY
1. **Adjacent nodes or neighbours**

 - For every edge, e = (u, v) that connects nodes u and v, the nodes 
u and v are the end-points and are said to be the adjacent nodes or neighbours.

2. **Degree of a node** 
- Degree of a node u, __deg(u)__, is the total number of edges containing the node u. 
If deg(u) = 0, it means that u does not belong to any edge and such a node is known as an isolated 
node.

3. more:
- regular graph
- path
- closed path
- ``simple path``(A path in which the first and the last vertices are same. A simple cycle has no repeated 
edges or vertices (except the first and last vertices).)
- cycle
- connected graph 
- ``complete graph:``
 (__*A complete graph has n(n–1)/2 edges, 
where n is the number of nodes in G*__)
- **``Size of a graph``** The size of a graph is the total number of edges in it.