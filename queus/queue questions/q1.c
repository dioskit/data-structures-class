/*******
 * reverse first k elements of a queue
 * take out k elements of a queue 
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXSIZE 100

int queue[MAXSIZE];
int front = -1;
int rear = -1;

bool isempty();
void enqueue(int x);
int dequeue();
void reverse(int k);
void print();

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for(int i = 0; i < 10; i++) enqueue(arr[i]);
    print();
    for(int i = 0; i < 10; i++) dequeue();
    print();
    reverse(5);
    print();
    return 0;
}

bool isempty(){
    if(-1 == rear && -1 == front){
        printf("queue is emppty\n");
        return true;
    }
    else{
        return false;
    }
}

void enqueue(int x){
    if(front == (rear + 1)% MAXSIZE){
        printf("queue full\n");
        return;
    }
    else if(isempty()){
        front = rear = 0;
    }
    else rear = (rear + 1)% MAXSIZE ;
    queue[rear] = x;
    return; 
}

int dequeue(){
    int temp = queue[front];
    if(isempty()) return -1;
    else if(front == rear) front = rear = -1;
    else front = (front + 1) % MAXSIZE;
    return temp;
}
void reverse(int k){
    k--;
    int length = k + 1;
    int a[length];
    for(int i = 0; i < k; i++) a[i] = dequeue();
    for(int i = k; i > 0; i--) enqueue(a[i]);
}
void print(){
    for(int i = 0; i != (rear + 1)% MAXSIZE ; i++) printf("%d ",queue[i]);
    printf("\n");
}
