/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode* root) {
    if(!root){
        return 0;
    }
    
    struct TreeNode* qu[10000] = {0};
    struct TreeNode* curr = NULL;
    int head,tail,level,max,sum = 0;

    qu[tail++] = root;
    max = root->val;
    int ret_level = 1;
    int actual_level = 0;

    while(head<tail){
        level = tail;
        sum = 0;
        while(head<level){
            curr = qu[head++];
            sum+= curr->val;
            if(curr->left)
                qu[tail++] = curr->left;
            if(curr->right)
                qu[tail++] = curr->right;
        }
        actual_level++;
        if(sum > max){
            max = sum;
            ret_level = actual_level;
        }
    }

    return ret_level;
}