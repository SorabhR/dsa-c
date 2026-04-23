//Rember in array with duplicate elements binary search has changes

#include "stdlib.h"

int compare(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    
    // Returns 1 if arg1 > arg2, -1 if arg1 < arg2, 0 otherwise.
    // Safe from overflow!
    return (arg1 > arg2) - (arg1 < arg2);
}

int binary_search(int *arr,int n,long long val){
    int l = 0;
    int h = n-1;
    int mid = 0;
    while(l <= h){
        mid = l + (h-l)/2;
        if(arr[mid] == val){
            h = mid;
            if(h==l){
                break;
            }
        }else if(arr[mid] < val){
            l = mid+1;
        }else{
            h = mid-1;
        }
    }
    if(mid == n && arr[mid] < val){
        return -1;
    }
    else if(arr[mid] < val){
        return mid+1;
    }else{
        return mid;
    }
    
}


int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {

    int *ret = (int*)malloc(sizeof(int) * spellsSize);
    long long search_result = 0;

    qsort(potions,potionsSize,sizeof(int),compare);
    int idx = 0;
    
    for(int i = 0;i<spellsSize;i++){
        search_result = (success + spells[i] - 1) / spells[i];
        idx = binary_search(potions,potionsSize,search_result);

        if(idx != -1)
            ret[i] = potionsSize - idx;
        else
            ret[i] = 0;
    }
    *returnSize = spellsSize;
    return ret;
}