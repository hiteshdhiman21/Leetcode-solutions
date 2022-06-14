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
    
    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL) return true;
        else if(root == NULL || subRoot == NULL) return false;
        
        return root->val == subRoot->val && isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);          
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) return true;
        else if(root == NULL || subRoot == NULL) return false;
        
        bool ans = false;
        return isIdentical(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }
    //T - O(n1*n2)
    //S - O(n1+n2)
};