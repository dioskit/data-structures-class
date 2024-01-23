int linear_search(int a[], int n,int ele){
    for(int i = 0; i < n; i++)
        if(a[i] == val)
            return i+1;

    return -1;
}
swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void selection(int *arr, int len){
    for(int i = 0; i < len; i++){
        for(int j = i +1; j < len; j++){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main(){
    int a[] = {1,2,3,4,5,6,8,9,5,1,26,65,5,5,4,65,22,4};
    int len = sizeof(a)/sizeof(a[0]);
    int ele = 22;
    int found = linear_search(a,len,ele);
    if(found == -1)
    printf("not found")
    else
    printf("found at %d position",found);

}