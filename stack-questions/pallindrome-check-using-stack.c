#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char x);
char pop();
bool isempty();
bool ispallindrome(char *string, int length);

void lower(char *string) {
    for (; *string; ++string) 
        *string = tolower(*string);
}
int main(){
    // char string[] = "tsewaNgxgnawEst";
    char string[100];
    printf("enter a string:");
    scanf(" %s", string);
    lower(string);
    // isempty()?printf("stack is empty\n"):printf("");
    ispallindrome(string,strlen(string))?printf("string is pallindrome"):printf("string is not pallindrome");
    
    return 0;
}

void push(char x){
    top++;
    stack[top] = x;
}
char pop(){
    char temp = stack[top];
    top--;
    return temp;
}
bool isempty(){
    return (top == -1);
}
bool ispallindrome(char *string, int length){
    int i = 0;
    bool ispallindrome;
    do{
        push(string[i]);
        i++;
    }while(string[i] != 'x');
    i++;
    while(!isempty()){
        (string[i++]!=pop())?(ispallindrome = false):(ispallindrome=true);
    }
    if(string[i] != '\0') 
        ispallindrome = false;
    return ispallindrome;
}
