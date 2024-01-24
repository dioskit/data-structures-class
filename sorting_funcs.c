#include <stdio.h>

void swap(int *a, int *b);
void bubble_sort(int *arr, int length);
void inserton_sort(int *arr, int length);
int linear_search(int *arr, int length, int search_element);
int binary_search(int *arr, int start, int end, int search_element);

void print(int *arr, int length){
    for(int i = 0; i < length; i++)
        printf("%d ",arr[i]);
    printf("\n");
}
int main(){
    int arr[] = {9,8,7,45,53,59,62,15,-12,-62,89,56,78,42,45,53,15,48,86,62,15,35,75,59};
    int length = sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting:\n");
    print(arr,length);
    printf("choosi type of sorting:\n\t1 for bubble\n\t2 for insertion\n\t Enter: ");
    int opt;
    scnaf("%d",&opt);
    switch (opt){
        case 1:
            bubble_sort(arr,length);
            printf("after sorting: ");
            print(arr,length);
            break;
        case 2:
            inserton_sort(arr,length);
            printf("after sorting: ");
            print(arr,length);
            break;
        default:
            printf("invalid option\n");
            break;
    }
    printf("Enter search element: ");
    int se;
    scnaf("%d",&se);
    printf("choose type of search:\n\t1 for linear\n\t2 for binary\n\t Enter: ");
    int opt_ser;
    scnaf("%d",&opt_ser);
    switch (opt){
        case 1:
            int flag1 = linear_search(arr,length,se);
            if(flag1 == -1)
            printf("%d element is not in arry\n",se);
            else
            printf("%d element is at postion %d\n",se,flag1 + 1);
            break;
        case 2:
            int flag2 = binary_search(arr,0,length,se);
            if(flag2 == -1)
            printf("%d element is not in arry\n",se);
            else
            printf("%d element is at postion %d\n",se,flag2 + 1);

            break;
        default:
            printf("invalid option\n");
            break;
    }
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int *arr, int length){
    for(int i = 0; i < length; i++)
        for(int j = i + 1; j < length - i; j++)
            if(arr[i] > arr[j])
                swap(&arr[i],&arr[j]);
}
void inserton_sort(int *arr, int length){
    for( int i = 1; i < length; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int linear_search(int *arr, int length, int search_element){
    for(int i = 0; i < length; i++)
        if(arr[i] == search_element)
            return i;
        else 
            return -1;
}
int binary_search(int *arr, int start, int end, int search_element){
    if(start > end)
        return -1;

    else if(arr[(start + end)/2] == search_element)
        return (start + end)/2;

    else if(arr[(start + end)/2] > search_element){
        end = (start + end)/2 - 1;
        binary_search(arr,start,end,search_element);
    }

    else if(arr[(start + end)/2] == search_element){
        end = (start + end)/2 - 1;
        binary_search(arr,start,end,search_element);
    }
}