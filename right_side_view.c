/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* ret = (int*)malloc(100*sizeof(int));
    if(!root){
        *returnSize = 0;
        return ret;
    }
    
    struct TreeNode* qu[100] = {0};
    struct TreeNode* curr = NULL;
    int head,tail,level,count = 0;

    qu[tail++] = root;
    // ret[count++] = root->val;

    while(head<tail){
        level = tail;
        while(head<level){
            curr = qu[head++];
            if(curr->left)
                qu[tail++] = curr->left;
            if(curr->right)
                qu[tail++] = curr->right;
        }
        ret[count++] = qu[level-1]->val;
    }

    *returnSize = count;
    return ret;
}