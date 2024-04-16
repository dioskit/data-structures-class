#include <stdio.h>

int gcd(int x, int y);
int main(){
    printf("enter numbers: ");
    int x,y;
    scanf("%d %d",&x,&y);
    int res = gcd(x,y);
    printf("gcd of %d and %d is %d\n",x,y,res);
    return 0;
}
int gcd(int x, int y){
    if(y%x == 0) return(x);
    else return gcd(y, y%x);
}