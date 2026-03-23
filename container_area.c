//imp takeway was since min of the height is used always move pointer where value is small

#include "stdbool.h"
#include "stdio.h"


int maxArea(int* height, int heightSize) {
    int i = 0;
    int j = heightSize - 1;
    int max = 0;
    int area = 0;
    int min_height = 0;
    while(j>i){
        min_height = height[i] > height[j] ? height[j] : height[i];
        area = min_height * (j-i);

        if(area > max)
            max = area;
        if(height[i] > height[j])
            j--;
        else
            i++;
    }
    return max;
}

int main(){
    int A[] = {1,1};
    int n = sizeof(A)/sizeof(A[0]);
    printf("%d\r\n",maxArea(A,n));
}