#include<stdio.h>
#include <stdbool.h>
#define MAZ_SIZE 100

int arry[MAX_SIZE];


int choice(void);
bool exit_func();
void menu_function(void);
void insertion(int *arr);  //from here

int main(){

    menu_function();

    return 0;
}

int choice(void){
    //choice for insretion deletion and searching    
    int choice_number;
    printf("\nPRESS:\n1 > insertion\n2 > deletion\n3 > searching\n");
    scanf("%d",&choice_number);
    if(choice_number != 1 ||choice_number != 2 ||choice_number != 3 ){
        printf("invalid choice\n");
        return -1;  //-1 is for invalid choice
    }
    return choice_number;
}
void menu_function(void){
    do{
        //here here
        printf("Menu:\n");
        int structure = choice();
        switch(structure){
            case 1:
                //insertion

                break;
            case 2:
            //deletion
                break;
            case 3:
            //searching
                break;
            case -1:
            //out 
                break;
        }
    }while(!exit_func());
}
bool exit_func(){     
    char yes_no;     
    printf("exit?....(y/n):");     
    scanf(" %c",&yes_no);     
    switch(yes_no){         
        case 'y':             
            return true;             
            break;         
        case 'n':             
            return false;    
            break;
    }
}
