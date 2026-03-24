#include "stdio.h"
#include "stdlib.h"

int longestOnes(int* nums, int numsSize, int k) {
    int max = 0;
    int i = 0;
    int count = 0;
    int allowed_flips = k;
    int start = 0;
    while(i<numsSize){
        if(!nums[i]){
            if(allowed_flips > 0){
                allowed_flips--;
            }
            else{
                while(nums[start] != 0){
                    count--;
                    start++;
                }
                start++;
                count--;
            }
            count++;
        }
        else
            count++;
        if(count > max){
            max = count;
        }
        i++;
    }
    return max;
}

int main(){
    int A[] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    int n = sizeof(A) / sizeof(A[0]);
    printf("%d\r\n",longestOnes(A,n,k));
}