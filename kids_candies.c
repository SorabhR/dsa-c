#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

int max_value(int* candies, int candiesSize){
    int max = 0;
    for(int i = 0;i<candiesSize;i++){
        if(candies[i] > max){
            max = candies[i];
        }
    }
    return max;
}
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool *r = (bool*)malloc(candiesSize*sizeof(bool)); //result

    int maxValue = max_value(candies,candiesSize);

    for(int i = 0;i<candiesSize;i++){
        if(candies[i] + extraCandies >= maxValue){
            r[i] = true;
        }
        else{
            r[i] = false;
        }
    }
    return r;
}
int main(){
    // printf("%d\r\n",gcd_len(6,3));
    int candies[] = {2,3,5,1,3};
    int candiesSize = 5;
    int extraCandies = 3;
    int* ret = 0;

    bool* r = kidsWithCandies(candies,candiesSize,extraCandies,ret);
    printf("%d\r\n",r[3]);
}