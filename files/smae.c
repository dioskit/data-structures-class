#include<stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

int arry[MAX_SIZE];

int choice(void);
bool exit_func();
void menu_function(void);

//arry insertion functions
void insertion_type(int *arr);  //from here
void insert_1st(int *arr, int length);
void insert_last(int *arr, int length);
void insert_nth(int *arr, int length);

void print_arrry(int *arr, int length);

int main(){
    arry[0] = 9;
    menu_function();
    
    return 0;
}

int choice(void){
    //choice for insretion deletion and searching    
    int choice_number;
    printf("\nPRESS:\n1 > insertion\n2 > deletion\n3 > searching\n CHOOSE:  ");
    scanf("%d",&choice_number);
    if(choice_number < 1 || choice_number >3){
        printf("invalid choice G\n");
        return -1;  //-1 is for invalid choice
    }
    return choice_number;
}
void menu_function(void){
    do{
        //here here
        printf("Menu:\n");
        
        int structure_arry = choice();
        switch(structure_arry){
            case 1:
                //insertion
                insertion_type(arry);
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
void insert_1st(int *arr, int length){
    int insertion_element;
    printf("ENTER element: ");
    scanf("%d",&insertion_element);

    for(int i = 0; i < length; i++){
        arr[i+1] = arr[i];
    }
    arr[0] = insertion_element;
}
void insert_last(int *arr, int length){
    int insertion_element;
    printf("ENTER element: ");
    scanf("%d",&insertion_element);

    arr[length+1] = insertion_element;

}
void insert_nth(int *arr, int length){
    int insertion_element,position;
    printf("ENTER element: ");
    scanf("%d",&insertion_element);
    printf("ENTER postion: ");
    scanf("%d",&position);
    if( position > length || position < 1){
        printf("\nInvalid Position\n");
    }
    else{
        for(int i = position; i < length; i++){
            arr[i+1] = arr[i];
        }
        arr[position] = insertion_element;
    }
    

}
void insertion_type(int *arr){
    int length;
    for(int i = 0; i != '\0'; i++){
        length = i;
    }
    do{
        int type_of_insertion;  // at start, at nth postion , at the end
        printf("\nInsertion Type\n1.At Start.\n2.At Nth.\n3At End\n4.None\nEnter: ");
        scanf("%d", &type_of_insertion);
        
        switch(type_of_insertion){
            case 1:
                insert_1st(arr,length);
                length++;
                break;
            case 2:
                insert_nth(arr,length);
                length++;
                break;
            case 3:
                insert_last(arr,length);
                length++;
                break;
            default:
                printf("invalid choice:");
                break;
        }
    }while(!exit_func());
}

void print_arrry(int *arr, int length){
    for(int i = 0; i < length; i++){
        printf("%d ",arr[i]);
    }
}

