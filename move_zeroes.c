//Two poiner appraoch

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"

void moveZeroes(int* nums, int numsSize) {
    int i = 0; //where non zero element should be
    int j = 0; //where non zero element is
    int temp = 0;
    for(int x=0;x<numsSize;x++){
        
        if(nums[j] != 0 && j!=i){
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        j++;

        if(nums[i] != 0)
            i++;

    }
}

void printArray(int* A,int n){
    for(int i = 0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\r\n");
}

int main(){
    int nums[] = {0,1,0,2,3};
    int n = sizeof(nums)/sizeof(nums[0]);
    moveZeroes(nums,n);
    for(int a = 0;a<n;a++)
        printf("%d",nums[a]);
}