#include "stdio.h"

int pivotIndex(int* nums, int numsSize) {
    int index = -1;
    int post_sum[numsSize];
    int sum = 0;
    for(int i = numsSize-1;i>=0;i--){
        post_sum[i] = sum;
        sum += nums[i];
    }
    sum = 0;
    for(int j = 0;j<numsSize;j++){
        if(sum == post_sum[j])
            return j;
        sum += nums[j];
    }

    return index;
}

int main(){
    int A[] = {1,7,3,6,5,6};
    int n = sizeof(A)/sizeof(A[0]);
    printf("%d\r\n",pivotIndex(A,n));
}