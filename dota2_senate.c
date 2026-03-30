//very nice problem do revisit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* predictPartyVictory(char* senate) {
    int n = strlen(senate);
    
    // Create two queues to store the indices
    int* radiant = (int*)malloc(n * sizeof(int));
    int* dire = (int*)malloc(n * sizeof(int));
    
    int r_head = 0, r_tail = 0;
    int d_head = 0, d_tail = 0;

    // Fill the queues with initial positions
    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            radiant[r_tail++] = i;
        } else {
            dire[d_tail++] = i;
        }
    }

    // Simulate the voting process
    while (r_head < r_tail && d_head < d_tail) {
        if (radiant[r_head] < dire[d_head]) {
            // Radiant bans Dire: Radiant moves to the next round
            // We add n to preserve the relative order for the next round
            radiant[r_tail++] = radiant[r_head] + n;
        } else {
            // Dire bans Radiant: Dire moves to the next round
            dire[d_tail++] = dire[d_head] + n;
        }
        r_head++;
        d_head++;
    }

    // Clean up memory
    char* result = (r_head < r_tail) ? "Radiant" : "Dire";
    
    // Note: In a real app, you'd free(radiant) and free(dire) here.
    // However, on LeetCode, we return the string literal.
    return result;
}