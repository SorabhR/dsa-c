//major takeaway when you want to avoid current element use prefix and suffix

#include "stdio.h"
#include "stdlib.h"
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *r = (int*)malloc(numsSize*sizeof(int));
    *returnSize = numsSize;

    r[0] = 1;
    //prefix sum
    for(int i=1;i<numsSize;i++){
        r[i] = r[i-1]*nums[i-1];
    }

    int right = 1;
    for(int i = numsSize-1;i>=0;i--){
        r[i] = r[i]*right;
        right *= nums[i];
    }

    return r;
}

void printArray(int* A,int n){
    for(int i = 0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\r\n");
}

int main(){
    int A[] = {1,2,3,4};
    int lenIp = sizeof(A)/sizeof(A[0]);
    int returnsize = 0;
    int *result = (int*)malloc(lenIp*sizeof(int));
    result = productExceptSelf(A,lenIp,&returnsize);
    printArray(result,lenIp);

}