/********
 * operations in queue
 * 1. enqueue or push
 * 2. dequeue or pop
 * 3. front or peek
 * 4. is empty
 * 
*/
//implementation
//arry based immpliment & linked list implimentation
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXSIZE 10

int A[MAXSIZE];
int front = -1;
int rear = -1;

bool isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }
    else{
        return false;
    }
}

void enqueue(int x){
    if((rear + 1) % MAXSIZE == front) return;
    else if(isEmpty()){
        front = 0;
        rear = 0;
    }
    else{
        rear = (rear + 1) % MAXSIZE;
    }
    A[rear] = x;
    return;
}

void dequeue(){
    if(isEmpty()) return;
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else  front = (front + 1) % MAXSIZE;
}

int Front(){
    return A[front];
}

void printQ(){
    if(isEmpty()) printf("empty queue\n");
    else{
        int frontt = front, reart = rear;
        while(frontt != reart){
            printf("%d ",A[frontt]);
            frontt = (frontt + 1) % MAXSIZE;
        }
    }
}

int main(){
    for(int i = 0; i < 10; i++){
        enqueue(i);
        printQ();
        for(int j = 0; j < 10; j++){
            enqueue(i+j);
            enqueue(i+j);
            dequeue();

        }
        printQ();
    }
}
