#include "stdio.h"
#include "stdlib.h"

int longestSubarray(int* nums, int numsSize) {
    int max = 0;
    int i = 0;
    int count = 0;
    int no_zeroes = 0;
    int start = 0;
    int end = 0;

    while(end<numsSize){
        if(!nums[end] && !no_zeroes)
            no_zeroes = 1;
        else if(!nums[end]){
            while(start <= end){
                if(!nums[start++])
                    break;   
            }
        }
        end++; //do this if its 1 or 0 with no_zeroes limited
        count = end-start-no_zeroes;
        if(count > max){
            max = count;
        }
        i++;
    }
    max = no_zeroes > 0 ? max : max-1;
    return max;
}

int main(){
    int A[] = {1,1,1};
    int n = sizeof(A) / sizeof(A[0]);
    printf("%d\r\n",longestSubarray(A,n));
}