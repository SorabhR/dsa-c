/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int gNode(struct TreeNode* root,int max){
    if(!root)
        return 0;
    int goodNode = 0;
    
    if(root->val >= max){
        goodNode++;
        max = root->val;
    }
    goodNode += gNode(root->left,max);
    goodNode += gNode(root->right,max);
    
    return goodNode;
}


int goodNodes(struct TreeNode* root){
    if(!root)
        return 0;
    int maxvalue = root->val;
    int goodNode = 0; //root is always a good node
    
    if(root->val >= maxvalue)
        goodNode++;
    goodNode += gNode(root->left,maxvalue);
    goodNode += gNode(root->right,maxvalue);
    
    return goodNode;
}