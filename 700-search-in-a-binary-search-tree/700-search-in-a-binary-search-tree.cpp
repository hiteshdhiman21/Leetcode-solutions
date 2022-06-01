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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *cur = root;
        while(cur){
            if(cur->val == val) return cur;
            else if(cur->val > val) cur = cur->left;
            else cur = cur->right;
        }
        
        return cur;
    }
    //T - O(h) = O(n) for skewed tree
    //S - O(1)
};