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
    
    int kthSmallest(TreeNode *root, int& k, int& cur){
        if(root == NULL) return -1;
        
        int ansLeft = kthSmallest(root->left, k, cur);
        if(ansLeft != -1) return ansLeft;
        
        cur++;
        if(k==cur) return root->val;
        
        int ansRight = kthSmallest(root->right, k, cur);
        return ansRight;
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int cur = 0;
        return kthSmallest(root, k, cur);
    }
};