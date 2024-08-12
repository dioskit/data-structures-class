// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

typedef struct Node{
    float coeff;
    int expo ;
    struct Node* link;
} node;

node* create(node* head);
node* insert(node* head, int co, int ex);

int main() {
    
    node * head = NULL;
    cout << "enter the plynomial\n";
    head = create(head);
    
    
    return 0;
}
node* insert(node* head, int co, int ex){
    node* temp;
    node* newP =  malloc(sizeof(node));
    newP -> coeff = co;
    newP -> expo = ex;
    newP -> link = NULL;
    
    if(head == NULL || ex > head -> expo){
        newP -> link = head;
        head = newP;
    }
    else{
        temp = head;
        while(temp -> link != NULL && temp -> link ->expo > ex) temp = temp -> link;
        newP -> link = temp -> link;
        temp -> link = newP;
    }
    return head;
    
}
node* create(node* head){
    int n;
    int i;
    float coeff;
    int expo;
    
    cout << "enter the number of terms:";
    cin >> n;
    
    for(i = 0; i < n; i++){
        cout << "enter coeff for term" << i+1;
        cin >> coeff;
        
        cout << "enter exponenet for term" << expo;
        head = insert(head,coeff,expo);
    }
    
}



























