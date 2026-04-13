#include "stdio.h"

#define REQ_SIZE 10000
typedef struct {
    int req[REQ_SIZE];
    int current_start;
    int current_end;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*) malloc(sizeof(RecentCounter));
    memset(obj->req,0,REQ_SIZE);
    obj->current_start = 0;
    obj->current_end = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->req[obj->current_end++]  = t;
    int allowed_range = t-3000;
    while(obj->req[obj->current_start] < allowed_range){
        obj->current_start++;
    }
    return obj->current_end-obj->current_start;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/