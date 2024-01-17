/*  
to make a module to
 insert 
 delete
 search
    liner search
    binary search
 functions for{
    arry
    stack
    queue
    tree
    graph
 }
 to make is menu dirven function
*/
#include<stdio.h>
#include <stdbool.h>

int choice(void);
int data_struct_choice(void);
void f_menu(void);



int main(){

    printf("-----------WELCOME-SCREEN-----------\n");
    f_menu();

    
    return 0;


}

int data_struct_choice(void){
    //choice for the type of data structure reuturens options
    int d_choice;
    printf("\nEnter your choice:\n1.Array\n2.Stack\n3. exitso on ...\nfor now only arry is avaialbe, choose 1 :");
    scanf("%d",&d_choice);

    // delete this part later
    if(d_choice != 1 || d_choice != 3)
        d_choice = -1;

    return d_choice;
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
void f_menu(void){
    bool exit_flag = false;
    do{
        switch(data_struct_choice()){
            case 1:
                printf("arry choice works\n");
                switch(choice()){         //arry modifications
                    case 1: //insertion
                        printf(" insertion option part working");
                        break;
                    case 2: //deletion
                        printf(" deletion option part working");
                        break;
                    case 3: //searching
                        printf(" searching option part working");
                        break;
                    default:
                        printf("Invalid choice for array modifications\n");
                        break;
                }
                break;

            case -1:                    //others option will be addes here
                printf("these options are not available yet\n");
                break;

            case 3:
                exit_flag = true;
                break;
                 
            default:
                break;
        }
    }while(!exit_flag);
}
