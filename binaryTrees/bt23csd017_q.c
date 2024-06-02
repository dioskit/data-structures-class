#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){

    int arr[8][8] = {
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,0,0},
        {1,0,0,1,1,0,1,1},
        {1,2,2,2,2,0,1,0},
        {1,1,1,0,0,0,1,0},
        {1,1,1,2,2,2,2,0},
        {1,1,1,1,1,2,1,1},
        {1,1,1,1,1,2,2,1}
    };

    int x = 3, y = 3, color = 3;
    //print option
    
    int search = arr[y][x];
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++){
            if(arr[i][j] == search){
                arr[i][j] = color;
            } 
        }
    
    int max = 8;

    for(int i = 0; i < max; i++){
        for(int j = 0; j < max; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}