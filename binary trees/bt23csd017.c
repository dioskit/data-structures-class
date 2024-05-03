#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

void change(int color, int x, int y, int search) {
    if(x >= 0 && x < 8 && y >= 0 && y < 8 && arr[y][x] == search) {
        arr[y][x] = color;
        change(color, x - 1, y, search);
        change(color, x + 1, y, search);
        change(color, x, y - 1, search);
        change(color, x, y + 1, search);
    }
}
void print(int arr[8][8]){
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}
int main() {
    int x, y, c;
    print(arr);

    printf("enter coordinate x:");
    scanf("%d ",&x);

    printf("enter coordinate y");
    scanf("%d ",&y);

    printf("enter pixel: ");
    scanf("%d",&c);

    int num = arr[y][x];
    change(c, x, y, num);

    print(arr);
    return 0;
}
