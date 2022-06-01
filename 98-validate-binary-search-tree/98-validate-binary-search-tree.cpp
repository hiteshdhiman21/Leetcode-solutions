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
    
    bool isValid(TreeNode *root, long lBound, long uBound){
        if(root == NULL) return true;
        else if(root->val <= lBound || root->val >= uBound) return false;
        
        return isValid(root->left, lBound, root->val) && isValid(root->right, root->val, uBound);
    }
    
    bool isValidBST(TreeNode* root) {
        //Intuition: Just push the constraints down from the upper nodes. If any node is not satisfying constraints return false. Else return true.
        //For any leftchild, only uBound constraint changes(uBound = node->val) and For any right child, only lBound constraint changes(lBound = node->val).
       return isValid(root, LONG_MIN, LONG_MAX); 
    }
    //T - O(n)
    //S - O(h) [Auxillary stack space]  
};