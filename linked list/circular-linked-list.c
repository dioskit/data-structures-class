#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define isEven(x) ((x % 2) == 0)

int stack[MAX_SIZE];
int top1 = -2, top2 = -1;

void push(int x, bool stackOne);
int pop(bool stackOne);
void print();

int main() {
    for (int i = 10; i < 25; i++)
        (isEven(i)) ? push(i, true) : push(i, false);

    push(100, true);
    print();

    int num1, num2;
    while (top1 != -2 && top2 != -1) {
        num1 = pop(true);
        num2 = pop(false);
        printf("OUT:\tstack one [ %d ]:  stack two [ %d ]\n", num1, num2);
    }
    printf("\n");

    return 0;
}

void push(int x, bool stackOne) {
    if (stackOne) {
        top1 += 2;
        stack[top1] = x;
    } else {
        top2 += 2;
        stack[top2] = x;
    }
}

int pop(bool stackOne) {
    int num;

    if (stackOne) {
        if (top1 == -2) return -1; // Indicate error condition
        num = stack[top1];
        top1 -= 2;
    } else {
        if (top2 == -1) return -1; // Indicate error condition
        num = stack[top2];
        top2 -= 2;
    }

    return num;
}

void print() {
    int temp1 = top1, temp2 = top2;
    while (temp1 >= 0 && temp2 >= 0) {
        printf("stack one [ %d ]:\tstack two [ %d ]\n", (temp1 >= 0) ? stack[temp1] : -1, (temp2 >= 0) ? stack[temp2] : -1);
        temp1 -= 2;
        temp2 -= 2;
    }
}
