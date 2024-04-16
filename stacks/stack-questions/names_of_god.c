#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int top = -1;

void generate_sums(int target, int current_sum, int current_combo[], int start);
void printcombo(int current_combo[], int length);
void push(int current_combo[], int i);
void pop();

int main() {
    int num = 10 ;
    int current_combo[MAX_SIZE];
    generate_sums(num, 0, current_combo, 1);
    return 0;
}

void generate_sums(int target, int current_sum, int current_combo[], int start) {
    if (current_sum == target) {
        printcombo(current_combo, top + 1);
        return;
    }
    if (current_sum > target) {
        return;
    }
    for (int i = start; i <= target + 1; i++) {
        push(current_combo, i);
        generate_sums(target, current_sum + i, current_combo, i);
        pop();
    }
}

void printcombo(int current_combo[], int length) {
    for (int i = 0; i < length; i++) {
        if (i + 1 == length) {
            printf("%d \n", current_combo[i]);
        } else {
            printf("%d + ", current_combo[i]);
        }
    }
}

void push(int current_combo[], int i) {
    top++;
    current_combo[top] = i; 
}

void pop() {
    top--;
}