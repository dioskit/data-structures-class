/**********
 * There are 100 doors in a row that are all initially closed. 
 * You make 100 passes by the doors. The first time through, visit every door and 'toggle' the door (if the door is closed, open it; if it is open, close it). 
 * The second time, only visit every 2nd door (i.e., door #2, #4, #6, ...) and toggle it. The third time, visit every 3rd door (i.e., door #3, #6, #9, ...), etc., until you only visit the 100th door
******/
#include <stdio.h>
#include <stdbool.h>

#define NUM_DOORS 100

void toggelDoors(bool doors[], int num_doors){
    for(int i = 1; i <= num_doors; i++){
        for(int j = i - 1; j < num_doors; j += i){
            doors[j] = !doors[j];
        }
    }
}

void printOpen(bool doors[], int num_doors){
    printf("Open doors: ");
    for(int i = 0; i < num_doors; i++){
        if(doors[i])
            printf("%d ", i+1);
    }
    printf("\n");
}
int main(){
    bool doors[NUM_DOORS] = {false}; // initially all doors is closed
    toggelDoors(doors, NUM_DOORS);
    printOpen(doors, NUM_DOORS);
    return 0;
}