/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MAX_PAIRS 50000
int pairSum(struct ListNode* head) {
    //create array of sum of 5*10^4 elements
    //max = 0
    //traverse even ele and then the odd element and keep pushing even
    //1,2,3,4,5,6
    if(head==NULL)
        return 0;
    
    int max = 0;
    int count = 0;
    int sum_arr[MAX_PAIRS] = {0};

    struct ListNode* curr = head->next;
    sum_arr[count++] = curr->val;
    
    while(curr->next){
        curr = curr->next->next;
        sum_arr[count++] = curr->val;
    }

    curr = head;
    int n = count;
    count = 0;
    sum_arr[n-1-count] = sum_arr[n-1-count] + curr->val;
    if(sum_arr[n-1-count] > max)
        max = sum_arr[n-1-count];
    count++;

    while(curr->next->next){
        curr = curr->next->next;
        sum_arr[n-1-count] = sum_arr[n-1-count] + curr->val;
        if(sum_arr[n-1-count] > max)
            max = sum_arr[n-1-count];
        count++;
    }



    return max;
}