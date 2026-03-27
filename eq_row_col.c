//something imp to know here is your row or col is unique so rather than storing element store row or col

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10007 // A prime number for better distribution

typedef struct {
    int* row;
    int size;
    int count;
} HashEntry;

// Simple hash function for an array of integers
unsigned int hash_row(int* row, int size) {
    unsigned int h = 0;
    for (int i = 0; i < size; i++) {
        // 31 is a common multiplier for hashing
        h = h * 31 + row[i];
    }
    return h % TABLE_SIZE;
}

// Helper to check if two rows are identical
bool are_equal(int* row1, int* row2, int size) {
    for (int i = 0; i < size; i++) {
        if (row1[i] != row2[i]) return false;
    }
    return true;
}

int equalPairs(int** grid, int gridSize, int* gridColSize) {
    HashEntry table[TABLE_SIZE] = {0};
    int n = gridSize;

    // 1. Record the Rows in the Hash Table
    for (int i = 0; i < n; i++) {
        unsigned int h = hash_row(grid[i], n);
        
        // Linear probing to handle collisions
        while (table[h].row != NULL && !are_equal(table[h].row, grid[i], n)) {
            h = (h + 1) % TABLE_SIZE;
        }
        
        if (table[h].row == NULL) {
            table[h].row = grid[i];
            table[h].size = n;
            table[h].count = 1;
        } else {
            table[h].count++;
        }
    }

    int totalPairs = 0;
    int* tempCol = (int*)malloc(n * sizeof(int));

    // 2. Scan the Columns and check the Hash Table
    for (int j = 0; j < n; j++) {
        // Extract column j into a temporary array
        for (int i = 0; i < n; i++) {
            tempCol[i] = grid[i][j];
        }

        unsigned int h = hash_row(tempCol, n);
        
        // Look for this column pattern in our "Row Cheat Sheet"
        while (table[h].row != NULL) {
            if (are_equal(table[h].row, tempCol, n)) {
                totalPairs += table[h].count;
                break;
            }
            h = (h + 1) % TABLE_SIZE;
        }
    }

    free(tempCol);
    return totalPairs;
}