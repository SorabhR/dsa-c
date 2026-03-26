#include "stdio.h"

int largestAltitude(int* gain, int gainSize) {
    int max = 0;    //starting point
    int alt = 0;
    for(int i = 0;i<gainSize;i++){
        alt += gain[i];
        if(alt > max){
            max = alt;
        }
    }
    return max;
}

int main(){
    int A[] = {-4,-3,-2,-1,4,3,2};
    int n = sizeof(A)/sizeof(A[0]);
    printf("%d\r\n",largestAltitude(A,n));
}