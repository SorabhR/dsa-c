//Takeaway you took bottom down approach which takes more memory and time could have taken top to bottom approach

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// int sumbranch(struct TreeNode* root,int targetSum,long int* arr,int* len){
//     if(!root){
//         *len = 0;
//         return 0;
//     }
    
//     int lenLeft = 0;
//     int lenRight = 0;
//     long int arrl[1000];
//     long int arrR[1000];
//     int count = 0;
//     count += sumbranch(root->left,targetSum,arrl,&lenLeft);
//     count += sumbranch(root->right,targetSum,arrR,&lenRight);

//     //push root and sums
//     int i=0;
//     int j=0;
//     while(i<lenLeft && i<lenRight){
//         if(arrl[i] == targetSum)
//             count++;
//         if(arrR[i] == targetSum)
//             count++;
        
//         arrl[i] += root->val;
//         arrR[i] += root->val;
//         arr[j++] = arrl[i];
//         arr[j++] = arrR[i];
//         i++;
//     }

//     while(i<lenLeft){
//         if(arrl[i] == targetSum)
//             count++;
//         arrl[i] += root->val;
//         arr[j++] = arrl[i];
//         i++;
//     }

//     while(i<lenRight){
//         if(arrR[i] == targetSum)
//             count++;
//         arrR[i] += root->val;
//         arr[j++] = arrR[i];
//         i++;
//     }
//     //we will also have to add the root element
//     arr[j++] = root->val;
//     *len = j;

//     return count;
// }


int sumbranch(struct TreeNode* root,int targetSum,int* arr,int len,int depth){
    if(!root)
        return len;
    
    arr[depth-1] = root->val;
    long sum = 0;
    for(int i=depth-1;i>=0;i--){
        sum+=arr[i];
        if(sum == targetSum)
            len++;
    }
    return sumbranch(root->left,targetSum,arr,len,depth+1) + sumbranch(root->right,targetSum,arr,len,depth+1) - len;
}


int pathSum(struct TreeNode* root, int targetSum) {
    if(!root)
        return 0;
    
    int arr[1000] = {0};
    int len = 0;
    int count = sumbranch(root,targetSum,arr,len,1);
    
    return count;

}