/*
checkBalancedParenthesis(exp){
    n length(exp)
    creat a stack:- s
    for(i = 0 to n -1){
        if exp[i] id '(' or { or [ push exp[i]
        else if exp[i] is ) or } or ]{
            if(s is empty0 || top does not pair with exp[i]) return false
            else pop()
        }
    }
    return s is empty ? true:false;
}
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max_size 100

struct Node {
    char exp;
    struct Node *next;
};
typedef struct Node Node;

void push(char x, Node **top);
void pop(Node **top);
bool ispair(Node *top, char x);
bool isempty(Node *top);
bool balanceCheck(int length, char list[]);

int main() {
    int index = 0;
    char exp[max_size];
    printf("enter: ");
    scanf("%s", exp);

    while (exp[index] != '\0') {
        index++;
    }

    Node *top = NULL;  // Initialize top to NULL
    bool balanced = balanceCheck(index, exp);
    (balanced) ? printf("balanced") : printf("not balanced");
    return 0;
}

void push(char x, Node **top) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->exp = x;
    newNode->next = *top;
    *top = newNode;
}

void pop(Node **top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    Node *temp = *top;
    *top = (*top)->next;
    free(temp);
}

bool ispair(Node *top, char x) {
    return top->exp == '(' || top->exp == '[' || top->exp == '{';
}

bool isempty(Node *top) {
    return (top == NULL) ? true : false;
}

bool balanceCheck(int length, char list[]) {
    Node *top = NULL;
    for (int i = 0; i < length; i++) {
        if (list[i] == '(' || list[i] == '{' || list[i] == '[')
            push(list[i], &top);
        else if (list[i] == ')' || list[i] == '}' || list[i] == ']') {
            if (isempty(top) || !(ispair(top, list[i])))
                return false;
            else
                pop(&top);
        }
    }
    return isempty(top);
}
