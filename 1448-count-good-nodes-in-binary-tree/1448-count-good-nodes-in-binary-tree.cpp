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
    int cnt = 0;
    void solve(TreeNode *root, int mx_val){
        if(root == NULL) return;
        
        if(root->val >= mx_val)
            cnt++;
        solve(root->left, max(root->val, mx_val));
        solve(root->right, max(root->val, mx_val));
    }
    
    int goodNodes(TreeNode* root) {
        solve(root, INT_MIN);
        return cnt;
    }
    
    //T - O(n)
    //S - O(h)
};