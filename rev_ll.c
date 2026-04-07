//takeaways understand where everyone points after everyloop update their address
//made a mistake as curr=curr->next which was poiting to prev after first loop 
//you have to take curr ahead after every loop since next is changed in prev loop dont use that


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL)
        return NULL;
    
    struct ListNode* prev = head;
    struct ListNode* curr = head;
    struct ListNode* nxt = curr->next;

    while(nxt){
        prev = curr;
        curr = nxt;
        nxt = curr->next;
        curr->next = prev;
    }
    head->next = NULL;
    return curr;
}