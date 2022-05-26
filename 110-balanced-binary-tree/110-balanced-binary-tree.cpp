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
    
    int checkBalance(TreeNode *root, bool& balance){
        if(root == NULL) return 0;
        int lh = checkBalance(root->left, balance);
        int rh = checkBalance(root->right, balance);
        if(abs(lh-rh) > 1) balance = false;
        return max(lh, rh)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        bool balance = true;
        checkBalance(root, balance);
        return balance;
    }
};