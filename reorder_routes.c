//revisit the problem


#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure to store edges in the adjacency list
typedef struct {
    int to;
    int is_original;
    int next; // Index of the next edge for the same city
} Edge;

Edge edge_pool[100000 * 2]; // 2 * (n-1) edges
int head[50001];            // Head of the linked list for each city
int edge_count = 0;

void add_edge(int u, int v, int original) {
    edge_pool[edge_count].to = v;
    edge_pool[edge_count].is_original = original;
    edge_pool[edge_count].next = head[u];
    head[u] = edge_count++;
}

void dfs(int city, bool* visited, int* count) {
    visited[city] = true;
    
    // Only loop through neighbors of THIS city
    for (int i = head[city]; i != -1; i = edge_pool[i].next) {
        int neighbor = edge_pool[i].to;
        if (!visited[neighbor]) {
            // If it's an original road leading AWAY from 0, flip it
            if (edge_pool[i].is_original) (*count)++;
            dfs(neighbor, visited, count);
        }
    }
}

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    // Reset global state for LeetCode
    edge_count = 0;
    memset(head, -1, sizeof(head));
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    int count = 0;

    // 1. Build Adjacency List (O(N))
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        add_edge(u, v, 1); // Original road
        add_edge(v, u, 0); // Reverse road (fake)
    }

    // 2. Start DFS from City 0 (O(N))
    dfs(0, visited, &count);

    return count;
}