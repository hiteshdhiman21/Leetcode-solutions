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
    
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int> &ds){
        if(root == NULL)
            return;
        
        targetSum -= root->val;
        ds.push_back(root->val);
        if(root->left == NULL && root->right == NULL){ //If node is a leaf
            if(targetSum == 0)
                res.push_back(ds);
            ds.pop_back();
            return;
        }
        
        solve(root->left, targetSum, res, ds);
        solve(root->right, targetSum, res, ds);
        ds.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> ds;
        solve(root, targetSum, res, ds);
        return res;
    }
    //T - O(n)
    //S - O(h)+O(n)
};