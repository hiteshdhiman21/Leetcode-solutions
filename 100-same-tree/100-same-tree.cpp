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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q) return true; //If both are null
        else if(!p || !q) return false; //If only one is null
        else if(p->val != q->val) return false; //the corresponding data is different
        else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    //T - O(n)
    //S - O(1)
};