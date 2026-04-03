//one mistake i was doing is considered head->next as even's head 
//which had changed when i changed odd->next

struct ListNode* oddEvenList(struct ListNode* head) {
    if(head == NULL)
        return NULL;
    
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* even_head = even;

    while(even && even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = even_head;
    return head;
}