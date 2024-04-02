#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100;

char* calculate(char* string[]);
void changeToNumber(char* string[],int num[],int length);

int main(){
    char string[] = {"1234"};

    return 0;
}

char* calculate(char* string[]){
    int numbers[4];
    changeToNumber(string, numbers, 4);
    
}
void changeToNumber(char* string[],int num[],int length){
    int bnum = atoi(string);
    int i;
    for(i = 0; bnum != 1; i++){
        num[i] = bnum/10;
        bnum /= 10;
    }
    num[i] = bnum;
}

/***
 * 
 * first change the numbers to arrys of individuals
 * say 1 ,2 ,3, 4
 * now first + - * /
 * 
 * 
*/