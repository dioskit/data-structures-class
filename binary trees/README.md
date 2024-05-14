# introduction to trees
- What need to be stored?
- cost of operations
- memory useage
- ease of implementation

- trees can be used for storage of hirearcial  data:
eg organisational hirearcy of employes of a compaly
 - collection of nodes in a hirearcy
 - tree is a non linear data structure
 - top node is called root of the tree

nodes will have some data and link or referance to other data structure
root, childern, parent sibling, leaf nodes
                            
                           1 root
                    _______|_______       
                    |              |
                    2              3            //2,3 are children nodes of 1
                 ___|_____       __|____
                |   |    |       |     |
                4   5    6       7     8         //4,5,6 are childern of 2, and 2 is their parent node and 7.8 are childern of 3 ans so on 
                   _|_           |
                  |   |          |
                  9   10         11              // 9,10,11,4,6,7,8 are called leaf nodes since they no other nodes linked to them
## application
1. storing naturally hierarcial data eg:file system
2. organize data for quick search, insertion, deletion eg: binary search trees
3. Trie //dictionary
4. network routing algorithm 
so on 

#### binary tree
each node can have atmost 2 childern
##### Complete binary tree:
- all level s except possibly the last are cmopletely filled and all nodes are left as possible\
depth: how deep is level of nodes its called the height of the tree

Maximum number of nudes at level i = 2^i;\

if all nodes of a tree is filled the it is called **_perfect binary tree_**\
\
Maximun number of nodes in a tree with height h,(length of the longest route from root to leafs) \
**h = 2<sup>0</sup>+2<sup>61</sup>+. . .+2<sup>h</sup>**\
**h = 2<sup>h+1</sup>-1**\
**h = 2<sup>(_number of levels_)</sup>-1**


# TREE TRAVERSAL
- process of visiting each node in the tree exaclty once in some order.


visit -> **reading/processing** data in a node

## BREADTH FIRST
*_Consider them as a special type of graph_*

level order traversal 

visit all the at nodes at same level before visiting nodes at next level
- root node have level 0.
- next node will have level 1 and so on.

                           F root
                    _______|_______       
                    |              |
                    D              J //print or visit these nodes first then move to next ones 
                 ___|_____       __|____
                |   |    |       |     |
                B   E    G       K     H//next line to vist is level two
                   _|_           |
                  |   |          |
                  A   C          I    //now these nodes will be printed
                  
**NOW THE OUTPUT WILL BE [ F, D, J, B, E, G, K,H, A, C, I ]**
### TIME COMPLEXITY
for all CASES its O(n);
### SPACE COMPLEXITY
- O(1) -best case such as linked list
 - O(n) -for worst and average 


## DEPTH FIRST
### There are three types of depth first traversal
- **ROOT** *LEFT* *RIGHT* -> Preorder
- _LEFT_ **ROOT** _RIGHT_ -> Inorder
- _LEFT_ _RIGHT_ __ROOT__ -> Postorder