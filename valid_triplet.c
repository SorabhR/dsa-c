//my mistake was i tried to erase middle element 
//when i found something smaller than first one which was not needed

#include "stdbool.h"
#include "stdio.h"

bool increasingTriplet(int* nums, int numsSize) {
    int first = __INT_MAX__;
    int second = __INT_MAX__;
    for(int a = 0;a<numsSize;a++){
        if(nums[a] <= first)
            first = nums[a];
        else if(nums[a] <= second)
            second = nums[a];  
        else
            return true;
    }
    return false;
}

int main(){
    int A[] = {1,2,1,3};
    int n = sizeof(A)/sizeof(A[0]);
    printf("%d\r\n",increasingTriplet(A,n));
}