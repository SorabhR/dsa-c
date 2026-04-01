/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//could have used the slow and fast pointer logic for middle element 
#include "stdio.h"
#include "stdlib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head) {
    if(head == NULL){
        return NULL;
    }
    int middle = 0;
    int n = 0;
    struct ListNode* curr = head;
    while(curr != NULL){
        n++;
        curr = curr->next;
    }
    middle = (int)n/2;
    if(middle == 0){
        head = NULL;
        return head;
    }
    n=0;
    curr = head;
    while(n<middle-1){
        n++;
        curr = curr->next;
    }
    struct ListNode* temp = curr->next; //temp is the actuall middle element
    curr->next = temp->next;
    return head;
}