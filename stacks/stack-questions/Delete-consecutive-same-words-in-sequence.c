/****
 * Given a sequence of n strings,
 *  the task is to check if any two similar words come together and then destroy each other then print the number of words left in the sequence after this pairwise destruction.
 * Input : ab aa aa bcd ab
 * Output : 3
 * As aa, aa destroys each other so, 
 * ab bcd ab is the new sequence.
 * Input :  tom jerry jerry tom
 * Output : 0
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_WORD_LENGTH 40
#define MAX_SENTENCE_LENGTH 200
struct Node{
    char word[MAX_WORD_LENGTH];
    struct Node* next;
};
typedef struct Node Node;
Node * top = NULL;

Node* getNode(char *string);
void push(char *string);
void pop();
bool isempty();
int resulOut(char *sentence);

int main(){
    char sentence[MAX_SENTENCE_LENGTH];

    printf("enter a senteance: ");
    scanf("%[^\n]s",sentence);
    int total = resulOut(sentence);
    printf("%d",total);

    return 0;
}

Node* getNode(char *string){
    Node * newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, string);
    newNode -> next = NULL;
    return newNode;
}
void push(char *string){
    Node* newNode = getNode(string);
    newNode -> next = top;
    top = newNode;
}
void pop(){
    Node* temp = top;
    top = top -> next;
    free(temp);
}
bool isempty(){
    return (top == NULL);
}
int resulOut(char *sentence){
    char *token;
    token = strtok(sentence," ");
    int count = 0;
    while (token != NULL) {
        // note strcmp will return values 0 or 1
        if(!isempty() && strcmp(token,top->word) == 0){ 
            pop();
        }
        else{
            push(token);
        }
        token = strtok(NULL, " ");
    }
    while(!isempty()){
        pop();
        count++;
    }
    return count;
}
