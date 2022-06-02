/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        
        //Both nodes are on left side of root. Hence LCA is also on left side.
        if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        //Both are on right side of root. Hence LCA is also on right side
        else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        //One is on left side and other on right side, hence this is LCA.
        else return root;
    }
    //T - O(h) = O(logn)
    //S - O(h) = O(logn)
};