#include <stdio.h>

// Helper to sink a node down to its correct position
void siftDown(int* nums, int n, int i) {
    int largest = i;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        if (largest != i) {
            // Swap
            int temp = nums[i];
            nums[i] = nums[largest];
            nums[largest] = temp;
            
            i = largest; // Move down to the new position
        } else {
            break; // Property satisfied
        }
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    // 1. Build Max Heap (Bottom-up)
    for (int i = (numsSize / 2) - 1; i >= 0; i--) {
        siftDown(nums, numsSize, i);
    }

    // 2. Extract Max k-1 times
    for (int i = 0; i < k - 1; i++) {
        // Replace root with last element
        nums[0] = nums[numsSize - 1];
        numsSize--; // CRITICAL: Shrink the heap size
        siftDown(nums, numsSize, 0);
    }

    return nums[0];
}