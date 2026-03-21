#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

void merge(int *A, int l, int mid, int h,int* R){
    int len_left = mid; 
    int len_right = h;

    int i,j,k;
    i = l;
    j=mid+1;
    k=l;


    while(i<=len_left && j<= len_right){
        if(A[i] < A[j]){
            R[k++] = A[i++];
        }
        else{
           R[k++] = A[j++];
        }
    }
    for(;i<=len_left;i++){
        R[k++] = A[i];
    }
    for(;j<=len_right;j++){
        R[k++] = A[j];
    }

    for(int a = l;a<=h;a++){
        A[a] = R[a];
    }
}

void mergesort(int *A, int l, int h,int* R){
    if(l<h){
        int mid = (int) ((l+h)/2);
        mergesort(A,l,mid,R);
        mergesort(A,mid+1,h,R);
        merge(A,l,mid,h,R);
    }
}

void printArray(int* A,int n){
    for(int i = 0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\r\n");
}

int main(){
    int A[] = {6,3,4,1,8,5};
    int lenIp = sizeof(A)/sizeof(A[0]);
    int *R = (int*)malloc((lenIp)*sizeof(int));
    mergesort(A,0,lenIp-1,R);
    printArray(R,lenIp);
    return 0;
}