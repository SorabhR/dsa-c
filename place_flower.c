#include "stdbool.h"
#include "stdio.h"
#include "stdint.h"

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int flower_planted = 0;
    if(flowerbedSize == 1){
        flower_planted = flowerbed[0] == 0;
    }
    for(int i=0;i<flowerbedSize-1;i++){
        if(i==0 || i==flowerbedSize-2){
            if(flowerbed[i] == 0 && flowerbed[i+1] == 0)
                flower_planted++;
        }
        else{
            if(flowerbed[i] == 0 && flowerbed[i+1] == 0 && flowerbed[i+2] == 0){
                flowerbed[i+1] = 1;
                flower_planted++;
            }
        }
    }
    return flower_planted >= n;
}

int main(){
    int flowerbed[] = {1,0,0,0,0,1};
    int n = 2;
    int flowerbedSize = 6;
    printf("%d\r\n",canPlaceFlowers(flowerbed,flowerbedSize,n));
    return 0;
}