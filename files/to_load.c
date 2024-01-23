#include<stdio.h>



void swap(int *a, int *b);
void bubble_sort(int a[], int length);
void select_sort(int *a, int length);
void print_arry(int *a, int length);
int binary_search(int *a, int start, int end, int ele);

int main(){
    
   /* printf("enter length of arry: ");
    int length;
    scanf("%d",&length);
    
    int arr[length];

    for(int i = 0; i < length; i++){
        printf("enter element: ");
        scanf("%d",&arr[i]);
    }*/
    int length = 10;
    int arr[10] = {9,8,7,6,5,43,2,1,0,-1};
    
    printf("arry before sorting\n");
    print_arry(arr, length);
    //bubble_sort(arr, length);
    select_sort(arr, length);
    printf("\narry after sorting \n");
    print_arry(arr, length);
    
    printf("enter element to search for: ");
    int search_ele;
    scanf("%d",&search_ele);
    
    int found = binary_search(arr,0,length-1,search_ele);
    
    if(found == -1){
        printf("not found");
    }
    else if(arr[found] == search_ele){
        printf("element is found at postion %d",found + 1);
    }   
    else{
        printf("not found");
    }
        
    

    return 0;
}

//to swap pass the address when calling the function like swap(&a, &b);
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//this is bubble sorting
void bubble_sort(int a[], int length){
    for(int i = 0; i < length -1; i++){
        for(int j = 0; j < length - i -1 ; j++){
            if(a[j] > a[j+1]){
                swap(&a[j+1], &a[j]);
            }
        }
    }
}
//this is section sorting 
void select_sort(int *a, int length){
    for(int i = 0; i < length ; i++)
        for(int j = i + 1; j < length ; j++)
            if(a[i] > a[j])
                swap(&a[i],&a[j]);
    
}
void print_arry(int *a, int length){
    for(int i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");
}
//binary search program
int binary_search(int *a, int start, int end, int ele){
    if(start > end)
        return -1;
    else if(a[(start + end) / 2] == ele)
        return (start + end) / 2;
    else if(a[(start + end) / 2] > ele){
        end = (((start + end) / 2) - 1);
        binary_search(a,start,end,ele);
    }
    else if(a[(start + end) / 2] < ele){
        start = ((start + end) / 2) + 1;
        binary_search(a,start,end,ele);
    }
}