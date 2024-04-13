#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* getNode(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;  // Don't forget to return the created node
}

void insert(int x, Node** head) {
    Node* temp = getNode(x);
    temp->next = *head;
    *head = temp;
}

void print(Node* head) {
    printf("[");
    char c = ',';
    while (head != NULL) {
        if (head->next == NULL) c = '\0';
        printf("%d%c", head->data, c);
        head = head->next;
    }
    printf("]\n");
}

int sumList(Node* head1, Node* head2) {
    int num1 = 0, num2 = 0, i = 1, j = 1;  // i and j should start at 1, not 0
    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            num1 += head1->data * i;
            i *= 10;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            num2 += head2->data * j;
            j *= 10;
            head2 = head2->next;
        }
    }
    return num1 + num2;
}

int main() {
    int x;
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Read input for the first list
    while (1) {
        int res = scanf("%d", &x);
        if (res == 0) break;
        if (x == ',' || x == ' ' || x == '[' || x == ']') continue;
        insert(x, &head1);
    }

    // Read input for the second list
    while (1) {
        int res = scanf("%d", &x);
        if (res == 0) break;
        if (x == ',' || x == ' ' || x == '[' || x == ']') continue;
        insert(x, &head2);
    }

    // Calculate the sum
    int sum = sumList(head1, head2);

    // Create a new linked list to store the result
    Node* resultHead = NULL;
    while (sum != 0) {
        insert(sum % 10, &resultHead);
        sum /= 10;
    }

    // Print the result
    print(resultHead);

    return 0;
}
