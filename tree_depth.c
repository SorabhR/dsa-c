/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(!root)
        return 0;
    
    int len = 0;

    len++;
    int len_left = maxDepth(root->left);
    int len_right = maxDepth(root->right);
    if(len_left > len_right){
        len = len + len_left;
    }
    else{
        len += len_right;
    }


    return len;
}