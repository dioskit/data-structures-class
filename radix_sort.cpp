#include <iostream>
#include <vector>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to get the maximum value in the linked list
int getMax(Node* head) {
    int maxVal = head->data;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->data > maxVal)
            maxVal = current->data;
        current = current->next;
    }
    return maxVal;
}

// Function to perform counting sort based on the digit represented by exp
void countSort(Node*& head, int exp) {
    vector<Node*> buckets[10];
    Node* current = head;

    // Distribute nodes into buckets
    while (current != nullptr) {
        int index = (current->data / exp) % 10;
        buckets[index].push_back(current);
        current = current->next;
    }

    // Collect nodes from buckets and rebuild the linked list
    Node* newHead = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < 10; ++i) {
        for (Node* node : buckets[i]) {
            if (newHead == nullptr) {
                newHead = node;
                tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
    }
    tail->next = nullptr;
    head = newHead;
}

// Function to perform radix sort on the linked list
void radixSort(Node*& head) {
    int maxVal = getMax(head);
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSort(head, exp);
    }
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(170);
    head->next = new Node(45);
    head->next->next = new Node(75);
    head->next->next->next = new Node(90);
    head->next->next->next->next = new Node(802);
    head->next->next->next->next->next = new Node(24);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(66);

    cout << "Original list: ";
    printList(head);

    radixSort(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
