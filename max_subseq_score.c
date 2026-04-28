//nice problem 
//first sort n2 in descending order helps us get the kth min value
//then check if n1 is also reduncing dont change

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// 1. Structure to keep nums1 and nums2 together
typedef struct {
    int n1;
    int n2;
} Pair;

// 2. Comparator for sorting pairs by nums2 in DESCENDING order
int comparePairs(const void* a, const void* b) {
    return ((Pair*)b)->n2 - ((Pair*)a)->n2;
}

// 3. Min-Heap Functions (to keep the largest k elements of nums1)
void heapifyUp(int* heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] > heap[idx]) {
            int temp = heap[parent];
            heap[parent] = heap[idx];
            heap[idx] = temp;
            idx = parent;
        } else break;
    }
}

void heapifyDown(int* heap, int size, int idx) {
    while (1) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest != idx) {
            int temp = heap[idx];
            heap[idx] = heap[smallest];
            heap[smallest] = temp;
            idx = smallest;
        } else break;
    }
}

long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    // A. Create and Sort Pairs
    Pair* pairs = (Pair*)malloc(nums1Size * sizeof(Pair));
    for (int i = 0; i < nums1Size; i++) {
        pairs[i].n1 = nums1[i];
        pairs[i].n2 = nums2[i];
    }
    qsort(pairs, nums1Size, sizeof(Pair), comparePairs);

    // B. Setup Min-Heap for nums1 elements
    int* minHeap = (int*)malloc(k * sizeof(int));
    int heapSize = 0;
    long long currentSum = 0;
    long long maxRes = 0;

    // C. Iterate through sorted pairs
    for (int i = 0; i < nums1Size; i++) {
        int val1 = pairs[i].n1;
        int val2 = pairs[i].n2;

        // Add current nums1 to heap and sum
        if (heapSize < k) {
            minHeap[heapSize] = val1;
            currentSum += val1;
            heapifyUp(minHeap, heapSize);
            heapSize++;
        } else if (val1 > minHeap[0]) {
            // If new value is bigger than the smallest in our top-k, swap it
            currentSum = currentSum - minHeap[0] + val1;
            minHeap[0] = val1;
            heapifyDown(minHeap, k, 0);
        }

        // D. If we have exactly k elements, calculate the score
        if (heapSize == k) {
            long long score = currentSum * val2;
            if (score > maxRes) maxRes = score;
        }
    }

    free(pairs);
    free(minHeap);
    return maxRes;
}