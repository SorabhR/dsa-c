//Points to remeber in algo
//partition is the main function here
//In partition keep i<=h condn and that allows without use of infinity and avoids overflow
//In swap keep in mind do only if j>i
//also recurrsively call on l,p-1 this will help when you have array of all same elements 
//otherwise it will go to infinite loop



#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

void swap(int* a, int* b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

int partition(int* A,int l,int h){
    int i = l;
    int j = h;

    int pivot = A[l];

    while(i<j){
        while(i<=h && A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(j>i)
            swap(&A[i],&A[j]);
    }
    swap(&A[l],&A[j]);
    return j;
}

void quickSort(int *A, int l, int h){
    if(l<h){
        int p = partition(A,l,h);
        quickSort(A,l,p-1);
        quickSort(A,p+1,h);
    }
}

void printArray(int* A,int n){
    for(int i = 0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\r\n");
}

int main(){
    int A[] = {1,2,3,4,5,6};
    quickSort(A,0,5);
    printArray(A,6);
    return 0;
}