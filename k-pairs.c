//can also use the hash map concept here

#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

int compare(const void *a,const void *b){
    return *((int*) a) - *((int*) b);
}

int maxOperations(int* nums, int numsSize, int k){
    if(numsSize == 1 || k == 1)
        return 0;
    qsort(nums,numsSize,sizeof(int),compare);

    int i = 0;
    int j = numsSize - 1;
    int count = 0;

    while(j>i){
        if(nums[i] + nums[j] == k){
            count++;
            i++;
            j--;
        }
        else if(nums[i] + nums[j] > k){
            j--;
        }
        else
            i++;
    }

    return count;
}

int main(){
    int A[] = {3,1,3,4,3};
    int n = sizeof(A)/sizeof(A[0]);
    printf("%d\r\n",maxOperations(A,n,2));
}