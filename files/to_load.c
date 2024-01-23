#include <stdio.h>

void swap(int *a, int *b);
void sort(int *arry, int length);
int search(int *arry, int start, int end, int search_element);
void print(int *arry, int length);

int main(){
    //we will take a predefined arry
    int arr[15] = {9,8,6,5,1,3,4,8,-4,6,7,5,3,-5,-9};
    int length = sizeof(arr)/sizeof(arr[0]);
    
    sort(arr,length);
    print(arr,length);
    
    printf("Enter element to search: ");
    int ele;
    scanf("%d",&ele);
    int index = search(arr,0,length,ele);
    if(index == -1)
        printf("%d does not exit in the arry\n",ele);
    else
        printf("%d is found at position %d\n",ele,index+1);
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int *arry, int length){
    for(int i = 0; i < length; i++)
        for(int j = i + 1; j < length; j++)
            if(arry[i] > arry[j])
                swap(&arry[i],&arry[j]);
}
int search(int *arr, int start, int end, int search_element){
    if(start > end)
        return -1;
    else if(arr[(start + end)/2] == search_element){
        return (start + end)/2;
    }
    else if(arr[(start + end)/2] > search_element){
        //mid + 1 is end
        end = (start + end)/2 - 1;
        search(arr,start,end,search_element);
    }
    
    else if(arr[(start + end)/2] < search_element){
        //mid + 1 is satrt
        start = (start + end)/2 + 1;
        search(arr,start,end,search_element);
    }
}
    
void print(int *arry, int length){
    for(int i = 0; i < length; i++)
        printf("%d ", arry[i]);
        
    printf("\n");
}
