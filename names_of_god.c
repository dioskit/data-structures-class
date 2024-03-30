#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


void generate_sums(int target, int current_sum, int current_combo[],int start){ //start is initially 1.
    if(current_sum == target){
        printcombo(current_combo); // function to print the combinations;
        return;
    }
    if(current_sum > target){
        return;
    }
    for(int i = start, i < target + 1, i++){
        push(current_combo,i);
        generate_sums(target,current_sum + 1, current_combo[], i);
        pop(current_combo);
    }
}
int main(){
    int num = 3;
int current_combo[MAX_SIZE];
}