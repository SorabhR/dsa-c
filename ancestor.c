struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // Base case: if we hit NULL or find p or q
    if (!root || root == p || root == q) return root;

    // Search left and right
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both sides found something, THIS node is the LCA
    if (left && right) return root;

    // Otherwise, return the one that wasn't NULL
    return left ? left : right;
}