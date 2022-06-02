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
        //Three cases:
        //1. Both nodes are on left side of root. Hence LCA is also on left side.
        //2. Both nodes are on right side of root. Hence LCA is also on right side.
        //3. One is on left side and other on right side, hence this is LCA.
        TreeNode *cur = root;
        while(cur && cur != p && cur != q){
            if(p->val < cur->val && q->val < cur->val) cur = cur->left;
            else if(cur->val < p->val && cur->val < q->val) cur = cur->right;
            else return cur;
        }
        
        return cur;
    }
    //T - O(h) = O(logn)
    //S - O(1)
};