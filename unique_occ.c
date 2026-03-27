#include "stdlib.h"
#include "stdbool.h"

#define TABLE_SIZE 10007

typedef struct Node{
    int value;
    int count;
    struct Node* next;
}Node;

Node* ht[TABLE_SIZE];


int hash(int key){
    if(key<0) key = -key;
    return key%TABLE_SIZE;
}

void init_table(){
    for(int i=0;i<TABLE_SIZE;i++)
        ht[i] = NULL;
}

bool insert_table(int value){
    int idx = hash(value);
    Node *current = ht[idx];
    while(current != NULL){
        if(current->value == value){
            current->count++;
            return 0;
        }
        current = current->next;
    }
    // 2. Create the new node
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return 0; // Always check malloc in C!

    newNode->value = value;
    newNode->count = 1;

    // 3. Point the new node to the current start of the list
    newNode->next = ht[idx];

    // 4. Update the table head to be our new node
    ht[idx] = newNode;
    return 1;
}

int getCount(int value){
    int idx = hash(value);
    Node *current = ht[idx];
    int count = 0;
    while(current != NULL){
        if(current->value == value){
            count = current->count;
            current->count = 0;
            return count;
        }
        current = current->next;
    }
    return count;
}

bool uniqueOccurrences(int* arr, int arrSize) {
    init_table();
    int i=0;
    int uniqueEle = 0;

    //insert all elements count
    while(i<arrSize){
        if(insert_table(arr[i])){
            uniqueEle++;
        }
        i++;
    }
    int countEle[uniqueEle];
    uniqueEle = 0;
    i = 0;
    int curr_count = 0;
    while(i<arrSize){
        curr_count = getCount(arr[i]);
        if(curr_count){
            for(int a=0;a<uniqueEle;a++){
                if(countEle[a] == curr_count)
                    return 0;
            }
            countEle[uniqueEle++] = curr_count;
        }
        i++;
    }
    return 1;

}