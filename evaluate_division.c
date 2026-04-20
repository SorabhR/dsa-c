#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 1. Dictionary for Strings
char dict[40][6];
int dict_size = 0;

// 2. The Adjacency List Data Structures
typedef struct {
    int to;
    double weight;
    int next;
} Edge;

Edge edge_pool[100]; // Max 40 equations * 2 directions = 80 edges
int head[40];
int edge_count = 0;

// Helper: Add string to dictionary
int get_id(char* str) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dict[i], str) == 0) return i;
    }
    strcpy(dict[dict_size], str);
    return dict_size++;
}

// Helper: Find existing string
int find_id(char* str) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dict[i], str) == 0) return i;
    }
    return -1;
}

// Helper: Add directed edge to the adjacency list
void add_edge(int u, int v, double weight) {
    edge_pool[edge_count].to = v;
    edge_pool[edge_count].weight = weight;
    edge_pool[edge_count].next = head[u];
    head[u] = edge_count++;
}

// The Optimized DFS
double dfs(int curr, int target, double current_product, bool* visited) {
    if (curr == target) return current_product;
    
    visited[curr] = true;
    
    // INSTEAD OF SCANNING 40 SLOTS, WE ONLY VISIT ACTUAL NEIGHBORS
    for (int i = head[curr]; i != -1; i = edge_pool[i].next) {
        int neighbor = edge_pool[i].to;
        
        if (!visited[neighbor]) {
            double result = dfs(neighbor, target, current_product * edge_pool[i].weight, visited);
            if (result != -1.0) {
                return result; 
            }
        }
    }
    return -1.0; 
}

double* calcEquation(char*** equations, int equationsSize, int* equationsColSize, 
                     double* values, int valuesSize, 
                     char*** queries, int queriesSize, int* queriesColSize, 
                     int* returnSize) {
    
    // Reset Globals
    dict_size = 0;
    edge_count = 0;
    memset(head, -1, sizeof(head)); // -1 means no edges yet
    
    // Build Adjacency List
    for (int i = 0; i < equationsSize; i++) {
        int u = get_id(equations[i][0]);
        int v = get_id(equations[i][1]);
        double weight = values[i];
        
        add_edge(u, v, weight);         // Forward edge
        add_edge(v, u, 1.0 / weight);   // Reverse edge
    }
    
    // Process Queries
    double* results = (double*)malloc(queriesSize * sizeof(double));
    *returnSize = queriesSize;
    
    for (int i = 0; i < queriesSize; i++) {
        int start_id = find_id(queries[i][0]);
        int target_id = find_id(queries[i][1]);
        
        if (start_id == -1 || target_id == -1) {
            results[i] = -1.0;
        } else if (start_id == target_id) {
            results[i] = 1.0;
        } else {
            bool visited[40] = {false};
            results[i] = dfs(start_id, target_id, 1.0, visited);
        }
    }
    
    return results;
}