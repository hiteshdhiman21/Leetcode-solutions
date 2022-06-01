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
    
    TreeNode* arrToBST(vector<int> &nums, int s, int e){
        //Step-1. For tree to be height balanced, every node should have almost equal nodes in both subtrees. In BST left subtree elements < root and right subtree elements > root. Hence we will take root->val = nums[mid], so that no. of leftsubtree nodes = no. of right subtree nodes.
        //Step-2. Call recursion to make left subtree and right subtree and connect them to root->left and root->right respectively.
        //Step-3. Return root.
        
        
        if(s>e) return NULL;
        
        int m = (s+e)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = arrToBST(nums, s, m-1);
        root->right = arrToBST(nums, m+1, e);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrToBST(nums, 0, nums.size()-1);
    }
    //T - O(n)
    //S - O(logn)
};