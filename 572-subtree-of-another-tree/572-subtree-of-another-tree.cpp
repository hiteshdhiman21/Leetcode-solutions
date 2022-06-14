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
    
    bool isIdentical(TreeNode* root, TreeNode* subRoot, bool act = false){
        if(root == NULL && subRoot == NULL) return true;
        else if(root == NULL || subRoot == NULL) return false;
        
        bool ans = root->val == subRoot->val && isIdentical(root->left, subRoot->left, true) && isIdentical(root->right, subRoot->right, true);
        
        if(!act)
        ans = ans || isIdentical(root->left, subRoot) || isIdentical(root->right, subRoot);
    
        
        return ans;             
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return isIdentical(root, subRoot, false);  
    }
    //T - O(n^2)
    //S - O(1)
};