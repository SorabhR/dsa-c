/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//direction 0->left 1->right

void trackZigZag(struct TreeNode* root,int* max,int len,int direction){
    if(!root){
        return;
    }
    len++;
    *max = *max > len ? *max : len;
    if(!direction){
        trackZigZag(root->left,max,len,!direction);
        trackZigZag(root->right,max,0,direction);
    }
    else{
        trackZigZag(root->left,max,0,direction);
        trackZigZag(root->right,max,len,!direction);
    }

}

int longestZigZag(struct TreeNode* root) {
    if(!root){
        return 0;
    }
    int max = 0;
    int len = 0;

    trackZigZag(root->right,&max,len,0);
    trackZigZag(root->left,&max,len,1);

    return max;
}