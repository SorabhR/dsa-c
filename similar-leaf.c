/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void get_leaves(struct TreeNode* root, int* len,int* tree){
    if(!root)
        return;
    if(!root->left && !root->right){
        tree[(*len)++] = root->val;
        return;
    }
    get_leaves(root->left,len,tree);
    get_leaves(root->right,len,tree);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    if(!root1 || !root2)
        return false;

    int left_tree[200];
    int right_tree[200];
    int leaves_left = 0;
    int leaves_right = 0;

    get_leaves(root1,&leaves_left,left_tree);
    get_leaves(root2,&leaves_right,right_tree);

    if(leaves_left != leaves_right)
        return false;

    for(int i=0;i<leaves_left;i++){
        if(left_tree[i] != right_tree[i])
            return false;
    }
    return true;

}