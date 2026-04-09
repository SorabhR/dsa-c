/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* FindMin(struct TreeNode* root){
    if(!root)
        return NULL;
    if(!root->left)
        return root;
    return FindMin(root->left);
}
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(!root)
        return NULL;
    
    if(key < root->val)
        root->left = deleteNode(root->left,key);
    else if(key > root->val)
        root->right =  deleteNode(root->right,key);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }else if(root->left == NULL){
            struct TreeNode* temp = root;
            root = root->right;
            free(temp);
        }else if(root->right == NULL){
            struct TreeNode* temp = root;
            root = root->left;
            free(temp);
        }else{
            struct TreeNode* temp = FindMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right,temp->val);
        }
    }

    return root;
}