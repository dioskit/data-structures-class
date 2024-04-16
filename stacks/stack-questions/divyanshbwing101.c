// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// #include <math.h>

// struct Node {
//     int diam;
//     struct Node* next;
// };
// typedef struct Node Node;
// struct stack {
//     Node* top;
// };
// typedef struct stack stack;

// stack* createStack();
// int push(stack* stack, int diam);
// int pop(stack* stack);
// int peek(stack* stack);
// int count(stack* stack);
// void print(stack* stack);
// int isEmpty(stack* stack);

// void moveDisk(stack* source, stack* destination);

// int main() {
//     stack* towerOne = createStack();
//     stack* towerTwo = createStack();
//     stack* towerThree = createStack();
//     int towerSize = 3;

//     if (isEmpty(towerOne) && isEmpty(towerTwo) && isEmpty(towerThree)) {
//         printf("Three empty stacks created\n");
//     }

//     printf("\nPutting %d plates of subsequently smaller diameter on towerOne\n", towerSize);

//     for (int i = towerSize; i > 0; i--) {
//         push(towerOne, i);
//     }

//     printf("\nPrinting Tower One:\n");
//     print(towerOne);
//     printf("\n\n");

//     printf("Testing pop() on Tower One (removing top value):\n");
//     printf("%d\n", pop(towerOne));
//     printf("Tower Size is now %d\n", towerSize - 1);
//     printf("\nPrinting updated list:\n");
//     print(towerOne);
//     printf("\n\n");

//     printf("Testing peek()\n");
//     printf("%d\n", peek(towerOne));
//     printf("\n");

//     printf("Testing count()\n");
//     printf("%d\n", count(towerOne));
//     printf("\n");

//     int total_moves = (int)(pow(2, count(towerOne)) - 1);

//     printf("Running Towers of Hanoi algorithm\n");

//     if (count(towerOne) % 2 != 0) {
//         for (int i = 1; i <= total_moves; i++) {
//             if (i % 3 == 1) {
//                 moveDisk(towerOne, towerThree);
//             } else if (i % 3 == 2) {
//                 moveDisk(towerOne, towerTwo);
//             } else if (i % 3 == 0) {
//                 moveDisk(towerTwo, towerThree);
//             }
//         }
//     } else if (count(towerOne) % 2 == 0) {
//         for (int i = 1; i <= total_moves; i++) {
//             if (i % 3 == 1) {
//                 moveDisk(towerOne, towerTwo);
//             } else if (i % 3 == 2) {
//                 moveDisk(towerOne, towerThree);
//             } else if (i % 3 == 0) {
//                 moveDisk(towerTwo, towerThree);
//             }
//         }
//     }

//     printf("Checking Tower Three count is equal to %d\n", towerSize - 1);
//     printf("Tower Three Count: %d\n", count(towerThree));
//     printf("\nChecking Tower Three elements are in ascending order\n");
//     print(towerThree);
//     printf("\n");

//     return 0;
// }

// stack* createStack() {
//     stack* stack = (stack*)malloc(sizeof(stack));
//     stack->top = NULL;
//     return stack;
// }

// int push(stack* stack, int diam) {
//     int status = 0;
//     Node* temp = (Node*)malloc(sizeof(Node));
//     temp->diam = diam;
//     temp->next = stack->top;
//     stack->top = temp;
//     if (stack->top->diam == diam) {
//         status = 1;
//     }
//     return status;
// }

// int isEmpty(stack* stack) {
//     return stack->top == NULL;
// }

// int pop(stack* stack) {
//     int value = INT_MIN;
//     if (stack->top) {
//         Node* temp = stack->top;
//         value = temp->diam;
//         stack->top = temp->next;
//         free(temp);
//     }
//     return value;
// }

// int count(stack* stack) {
//     int count = 0;
//     Node* temp = stack->top;
//     while (temp) {
//         count++;
//         temp = temp->next;
//     }
//     return count;
// }

// int peek(stack* stack) {
//     int value = INT_MIN;
//     if (stack->top) {
//         value = stack->top->diam;
//     }
//     return value;
// }

// void print(stack* stack) {
//     Node* temp = stack->top;
//     while (temp) {
//         printf("%d ", temp->diam);
//         temp = temp->next;
//     }
// }

// void moveDisk(stack* source, stack* destination) {
//     int tower1Top = pop(source);
//     int tower2Top = pop(destination);

//     if (tower1Top == INT_MIN) {
//         push(source, tower2Top);
//     } else if (tower2Top == INT_MIN) {
//         push(destination, tower1Top);
//     } else if (tower1Top > tower2Top) {
//         push(source, tower1Top);
//         push(source, tower2Top);
//     } else {
//         push(destination, tower2Top);
//         push(destination, tower1Top);
//     }
// }
