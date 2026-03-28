#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "stdio.h"

#define TABLE_SIZE 32

typedef struct Node{
    char value;
    int count;
    int arr_idx;
    struct Node* next;
}Node;

Node* ht[TABLE_SIZE];


int hash(char key){
    if(key<0) key = -key;
    key -= 'a';
    return ((int)key) & (TABLE_SIZE - 1);
}

void init_table(){
    for(int i=0;i<TABLE_SIZE;i++)
        ht[i] = NULL;
}

bool insert_table(char value,int arr_idx){
    int idx = hash(value);
    Node *current = ht[idx];
    while(current != NULL){
        if(current->value == value && current->arr_idx == arr_idx){
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
    newNode->arr_idx = arr_idx;

    // 3. Point the new node to the current start of the list
    newNode->next = ht[idx];

    // 4. Update the table head to be our new node
    ht[idx] = newNode;
    return 1;
}

int getCount(int value,int arr_idx){
    int idx = hash(value);
    Node *current = ht[idx];
    int count = 0;
    while(current != NULL){
        if(current->value == value && current->arr_idx == arr_idx){
            count = current->count;
            current->count = 0;
            return count;
        }
        current = current->next;
    }
    return count;
}

int compare(const void *a,const void *b){
    return *((int*)a) - *((int*)b);
}

bool closeStrings(char* word1, char* word2) {
    int n1 = strlen(word1);
    int n2 = strlen(word2);
    if(n1!=n2)
        return false;
    
    int i=0;
    int unique1 = 0;
    int unique2 = 0;
    init_table();
    
    while(i<n1){
        if(insert_table(word1[i],1)){
            unique1++;
        }
        if(insert_table(word2[i],2)){
            unique2++;
        }
        i++;
    }

    if(unique1 != unique2)
        return 0;

    i = 0;
    int count1[unique1];
    int count2[unique2];
    unique1 = 0;
    unique2 = 0;
    int countCurr1 = 0;
    int countCurr2 = 0;
    while(i<n1){
        countCurr1 = getCount(word1[i],1);
        countCurr2 = getCount(word1[i],2);
        if((countCurr1 && !countCurr2) || (countCurr2 && !countCurr1)){
            return 0;
        }
        if(countCurr1 && countCurr2){
            count1[unique1++] = countCurr1;
            count2[unique2++] = countCurr2;
        }
        i++;
    }

    //sort the count1 and count2 arrays
    qsort(count1,unique1,sizeof(int),compare);
    qsort(count2,unique2,sizeof(int),compare);

    for(int a = 0;a<unique1;a++){
        if(count1[a] != count2[a])
            return 0;
    }
    
    return 1;
}