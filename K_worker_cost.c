//nice way to use front index consumed and rear index consumed
//imp note len and index check where to do post-- and pre--
//check all condition of rear heap usage 

#include "stdbool.h"

typedef struct{
    int value;
    int index;
}Point;

void delete_and_add(Point* heap,int len){
    int parent_idx = 0;
    int smallest,left_child_idx,right_child_idx,temp;
    while(1){
        smallest = parent_idx;
        left_child_idx = 2*smallest+1;
        right_child_idx = 2*smallest+2;

        if(left_child_idx < len && heap[left_child_idx].value < heap[smallest].value)
            smallest = left_child_idx;
        if(right_child_idx < len && heap[right_child_idx].value < heap[smallest].value)
            smallest = right_child_idx;
        
        if(smallest != parent_idx){
            temp = heap[smallest].value;
            heap[smallest].value = heap[parent_idx].value;
            heap[parent_idx].value = temp;
        }
        else{
            break;
        }
        parent_idx = smallest;
    }
}

void heapify(Point* heap,int len){
    int parent_idx = 0;
    int smallest,left_child_idx,right_child_idx,temp;
    
    for(int i = (len-1)/2;i>=0;i--){
        parent_idx = i;
        while(1){
            smallest = parent_idx;
            left_child_idx = 2*parent_idx+1;
            right_child_idx = 2*parent_idx+2;

            if(left_child_idx < len && heap[left_child_idx].value < heap[smallest].value)
                smallest = left_child_idx;
            if(right_child_idx < len && heap[right_child_idx].value < heap[smallest].value)
                smallest = right_child_idx;
            
            if(smallest != parent_idx){
                temp = heap[smallest].value;
                heap[smallest].value = heap[parent_idx].value;
                heap[parent_idx].value = temp;
            }
            else{
                break;
            }
            parent_idx = smallest;
        }
    }
}

long long totalCost(int* costs, int costsSize, int k, int candidates) {
    Point heap_front[candidates];
    Point heap_rear[candidates];
    long long totalcost = 0;
    int front_heap_ele = 0;
    int rear_heap_ele = 0;
    int front_idx_consumed,rear_index_consumed;

    memset(heap_front,0,sizeof(heap_front));
    memset(heap_rear,0,sizeof(heap_rear));

    //heapify array of first candidates elements
    int len = candidates > costsSize ? costsSize : candidates;
    for(int i = 0;i<len;i++){
        heap_front[i].value = costs[i];
    }
    front_heap_ele = len;
    front_idx_consumed = len-1;
    heapify(heap_front,front_heap_ele);
    
    //heapify array of last candidates elements
    for(int i = costsSize-1 ;i >= (costsSize-candidates);i--){
        if(i > front_idx_consumed){
            heap_rear[rear_heap_ele++].value = costs[i];
        }
    }
    if(rear_heap_ele != 0)
        heapify(heap_rear,rear_heap_ele);
    rear_index_consumed = costsSize-rear_heap_ele;
    
    //check top of both heaps and choose where to pop from
    while(k>0){
        
        if(rear_heap_ele > 0 && ((heap_front[0].value > heap_rear[0].value) || front_heap_ele == 0 )){
            totalcost += heap_rear[0].value;
            if(rear_index_consumed - front_idx_consumed > 1)
                heap_rear[0].value = costs[--rear_index_consumed];
            else
                heap_rear[0].value = heap_rear[--rear_heap_ele].value;
            
            delete_and_add(heap_rear,rear_heap_ele);
        }else{
            totalcost += heap_front[0].value;
            if(rear_index_consumed - front_idx_consumed > 1)
                heap_front[0].value = costs[++front_idx_consumed];
            else
                heap_front[0].value = heap_front[--front_heap_ele].value;
            delete_and_add(heap_front,front_heap_ele);
        }
        k--;
    }

    return totalcost;
}