

typedef struct {
    int mySet[1000];
    int current_set_idx;
    int current_pop_idx;
    bool exists[1001];
} SmallestInfiniteSet;

void addElement(SmallestInfiniteSet* obj,int num){
    obj->mySet[obj->current_set_idx] = num;
    int parent_idx = 0;
    int current_idx = obj->current_set_idx;
    int temp = 0;
    while(1){
        parent_idx = (current_idx-1)/2;
        
        if(parent_idx >= 0 && obj->mySet[parent_idx] > obj->mySet[current_idx]){
            temp = obj->mySet[current_idx];
            obj->mySet[current_idx] = obj->mySet[parent_idx];
            obj->mySet[parent_idx] = temp;
            current_idx = parent_idx;
        }
        else
            break;
    }
    obj->exists[num] = 1;
    obj->current_set_idx++;
}

int popHead(SmallestInfiniteSet* obj){
    int ret = obj->mySet[0];
    obj->mySet[0] = obj->mySet[obj->current_set_idx-1];

    int smallest = 0;
    int temp = 0;
    int right_child = 0;
    int left_child = 0;
    int parent_idx = 0;
    int len = obj->current_set_idx;

    while(1){
        smallest = parent_idx;
        left_child = 2*parent_idx + 1;
        right_child = 2*parent_idx + 2;
        if(left_child < len && obj->mySet[left_child] < obj->mySet[smallest])
            smallest = left_child;
        if(right_child < len && obj->mySet[right_child] < obj->mySet[smallest])
            smallest = right_child;
        
        if(smallest != parent_idx){
            temp = obj->mySet[smallest];
            obj->mySet[smallest] = obj->mySet[parent_idx];
            obj->mySet[parent_idx] = temp;
            parent_idx = smallest;
        }
        else{
            break;
        }
    }

    obj->current_set_idx--;
    obj->exists[ret] = 0;
    return ret;
}

SmallestInfiniteSet* smallestInfiniteSetCreate() {
    SmallestInfiniteSet* obj = (SmallestInfiniteSet*)malloc(sizeof(SmallestInfiniteSet));
    memset(obj->mySet,0,sizeof(obj->mySet));
    memset(obj->exists,0,sizeof(obj->exists));
    obj->current_set_idx = 0;
    obj->current_pop_idx = 1;

    return obj;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    if(obj->current_set_idx == 0)
        return obj->current_pop_idx++;
    else
        return popHead(obj);
}

bool not_in_set(SmallestInfiniteSet* obj, int num){
    return !obj->exists[num];
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    if(num < obj->current_pop_idx && not_in_set(obj,num)){
        addElement(obj,num);
    }
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj);
}

/**
 * Your SmallestInfiniteSet struct will be instantiated and called as such:
 * SmallestInfiniteSet* obj = smallestInfiniteSetCreate();
 * int param_1 = smallestInfiniteSetPopSmallest(obj);
 
 * smallestInfiniteSetAddBack(obj, num);
 
 * smallestInfiniteSetFree(obj);
*/