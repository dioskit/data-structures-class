#include<stdio.h>

char stack[100];
int top = -1;

void push(char x){
    top++;
    stack[top] = x;
}
char pop(){
    char res = stack[top];
    top--;
    return res;
}
bool isempty(){
    return top == -1;
}

void check(char string[], int length)
    for(int i = 0 ; i < length; i++){
        if(string[i] == '(' || string[i] == '{}' ||string[i] == '[') push(string[i]);
        else{
            switch string[i]{
                case ']':

                case'}':

                case ')':

            }
        }
    }
}