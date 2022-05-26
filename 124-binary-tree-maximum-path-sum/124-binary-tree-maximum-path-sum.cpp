/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode *root, int& maxSum){
        if(root == NULL) return 0;
        int lsum = maxPathSum(root->left, maxSum); //Maxsum from the left subtree(0 or more linked nodes) 
        int rsum = maxPathSum(root->right, maxSum); //Maxsum from the right subtree(0 or more linked nodes) 
        int maxSumHere = root->val+lsum+rsum;  //Maxsum including this node.
        maxSum = max(maxSum, maxSumHere); //updating maxSum with best value at every node.
        
        return max(0, root->val + max(lsum, rsum)); 
        //Returning maxSum with this node as end-point so that upper node can directly to it to check for the m axSum including that node. If < 0, then not including this and any other below node.
    }
    
    int maxPathSum(TreeNode* root) {
        //Use same concept as in Max-diameter etc
        int maxSum = INT_MIN;
        maxPathSum(root, maxSum);
        return maxSum;
    }
    //T - O(n)
    //S - O(1)
};