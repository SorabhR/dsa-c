#include "stdlib.h"
#include "stdbool.h"

#define TABLE_SIZE 10007

typedef struct Node{
    int value;
    int array_index;
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

bool insert_table(int value,int array_index){
    int idx = hash(value);
    Node *current = ht[idx];
    while(current != NULL){
        if(current->value == value && current->array_index == array_index)
            return 0;
        current = current->next;
    }
    // 2. Create the new node
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return 0; // Always check malloc in C!

    newNode->value = value;
    newNode->array_index = array_index;

    // 3. Point the new node to the current start of the list
    newNode->next = ht[idx];

    // 4. Update the table head to be our new node
    ht[idx] = newNode;
    return 1;
}

bool isthere(int value,int index){
    int idx = hash(value);
    Node *current = ht[idx];
    while(current != NULL){
        if(current->value == value && current->array_index == index)
            return 1;
        current = current->next;
    }
    return 0;
}

int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    init_table();
    int unique1 = 0;
    int unique2 = 0;
    int i = 0;
    int** result = (int**)malloc(sizeof(int*)*2);
    int maxsize = nums1Size > nums2Size ? nums1Size : nums2Size;

    //insertion in table and got all unique elements in 1 and 2
    while(i<maxsize){
        if(i<nums1Size){
            if(insert_table(nums1[i],1)){
                unique1++;
            }
        }
        if(i<nums2Size){
            if(insert_table(nums2[i],2)){
                unique2++;
            }
        }
        i++;
    }
    result[0] = (int*)malloc(sizeof(int) * unique1);
    result[1] = (int*)malloc(sizeof(int) * unique2);

    unique1 = 0;
    unique2 = 0;
    i = 0;
    while(i<maxsize){
        if(i<nums1Size){
            if(!isthere(nums1[i],2)){
                result[0][unique1++] = nums1[i];
                insert_table(nums1[i],2);
            }
        }
        if(i<nums2Size){
            if(!isthere(nums2[i],1)){
                result[1][unique2++] = nums2[i];
                insert_table(nums2[i],1);
            }
        }
        i++;
    }
    
    *returnColumnSizes = (int*)malloc(sizeof(int)*2);
    returnColumnSizes[0][0] = unique1;
    returnColumnSizes[0][1] = unique2;
    *returnSize = 2;

    return result;
}