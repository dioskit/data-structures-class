/******
 * program to calculate postfix notations of singel digits
 * 
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char x);
int pop();
bool isempty();
int calculate(char *string);
int operate(int x, int y, char operator);
void flagerror();
bool isoperator(char operator);

int main(){
    char string[MAX_SIZE] = "23-56+*12-*";
    
    int result = calculate(string);
    printf("%d is the result of %s notation",result, string);

    return 0;
}

void flagerror(){
    printf("Error: expression is not proper.");
}
bool isoperator(char operator){
    return (operator == '+' || operator == '-' || operator == '*' || operator == '/');
}
int operate(int x, int y, char operator){
    int result;
    switch(operator){
        case '+':
        result = x + y;
        break;
        case '-':
        result = x - y;
        break;
        case '/':
        result = x / y;
        break;
        case '*':
        result = x * y;
        break;
    }
    return result;
}
int calculate(char *string){
    for(int i = 0; string[i] != '\0'; i++){
        if(isdigit(string[i])){
            int num = string[i] - '0';
            push(num);
        }
        else if(isoperator(string[i])){
            int m = pop();
            int n = pop();
            int result_num = operate(n,m,string[i]);
            push(result_num);
        }
        else{
            flagerror();
            break;
        }
    }
    return pop();
}
void push(char x){
    top++;
    stack[top] = x;
}
int pop(){
    int result = stack[top];
    top--;
    return result;
}
bool isempty(){
    return (top == -1);
}