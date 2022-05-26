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
    
    //The function will return height of the tree rooted at the given node
    int checkBalance(TreeNode *root, bool& balance){
        //Don't call checkBalance twice i.e. once for height calculation and then for checking if left and right subtrees are balanced or not.
        //Both work can be happen in one call. While calculating its height, it can also check if the given tree is balanced or not.
        //Function can return more than 2 values or can take some extra parameter
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
    //T - O(n)
    //S - O(1)
};