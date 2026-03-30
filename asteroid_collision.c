/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "stdlib.h"
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int *result = (int*)malloc(sizeof(int)*asteroidsSize);
    int topOfStack = 0;

    for(int i=0;i<asteroidsSize;i++){
        if(asteroids[i] < 0){
            if(topOfStack == 0 || result[topOfStack-1] < 0)
                result[topOfStack++] = asteroids[i];
            else{
                //this while can end
                //1 reach topofstack = 0
                //2 reached equal element
                //3 reached greater element
                //4 reached a negative element
                while((topOfStack>0) && (result[topOfStack-1] > 0) && (-asteroids[i] > result[topOfStack-1])){
                    topOfStack--;
                }
                if(topOfStack == 0 || result[topOfStack-1] < 0)
                    result[topOfStack++] = asteroids[i];
                else if(-asteroids[i] == result[topOfStack-1]){
                    topOfStack--;
                    continue;
                }
                else{
                    continue;
                }
                
            }
        }
        else{
            result[topOfStack++] = asteroids[i];
        }
    }

    *returnSize = topOfStack;
    return result;
}