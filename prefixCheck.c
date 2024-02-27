#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define max_size 100

typedef struct Node {
    int exp;  // Change data type to int
    struct Node* next;
} Node;

void push(Node** top, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->exp = x;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    Node* temp = *top;
    if (*top == NULL) return 0;  // Return a default value, or handle this case differently
    *top = (*top)->next;
    int res = temp->exp;
    free(temp);
    return res;
}

int perform(char operator, int a, int b) {
    switch (operator) {
        case '+':
            return b + a;
        case '-':
            return b - a;
        case '*':
            return b * a;
        case '/':
            return b / a;
        default:
            return 0;  // Handle an unknown operator, or add an error mechanism
    }
}

int evalPostfix(char exp[], int length) {
    Node* top = NULL;
    int num = 0;

    for (int i = 0; i <= length; i++) {
        if (isdigit(exp[i])) {
            num = num * 10 + (exp[i] - '0');
        } else if (exp[i] == ' ') {
            // Ignore spaces
        } else {
            push(&top, num);
            num = 0;  // Reset num for the next operand

            int operator1 = pop(&top);
            int operator2 = pop(&top);
            int res = perform(exp[i], operator1, operator2);
            push(&top, res);
        }
    }

    int result = pop(&top);
    free(top);
    return result;
}

int main() {
    char expression[max_size];
    printf("Enter: ");
    fgets(expression, max_size, stdin);  // Use fgets to read the whole line
    int length = strlen(expression);
    int result = evalPostfix(expression, length - 1);
    printf("Result is %d\n", result);
    return 0;
}
