#include <stdio.h>
#include <math.h>
int sd(int arr[],int length){
    int xSq = 0;
    for(int i = 0; i < length; i++){
        xSq += pow(arr[i],2);
    }
    int meanSq = pow(mean(arr,length),2);
    return sqrt(meanSq+xSq);
}

//mean
int mean(int arr[],int length){
    int res = 0;
    for(int i = 0; i < length; i++) res+=arr[i];
    res /= length;
    return res;
}
//mode 

//median

int tTest(int sample1[], int sample2[], int length1,int length2){
    
}
int main(){
    int number = 5;
    int sample1[5], sample2[5];
    for(int i = 0; i < 5; i++){
        sample1[i] = i;
        sample2[i] = i*2;
    }
    
}