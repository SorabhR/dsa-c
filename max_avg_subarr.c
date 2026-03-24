#include "stdio.h"
#include "math.h"

double findMaxAverage(int* nums, int numsSize, int k) {
    double sum = 0;
    double max = 0;
    int i = 0;
    for(;i<k;i++)
        sum += nums[i];
    max = sum;

    while(i<numsSize){
        sum += nums[i];
        sum -= nums[i-k];
        
        if(sum > max)
            max = sum;
        i++;
    }
    
    return (double)max/(double)k;
}

int main(){
    int A[] = {5};
    int n = sizeof(A)/sizeof(A[0]);
    int k = 1;
    printf("%f\r\n",findMaxAverage(A,n,k));
    return 0;
}