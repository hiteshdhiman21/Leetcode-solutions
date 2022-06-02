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
    
    TreeNode *bstBuild(vector<int>& preorder, int &i, int uBound){
        if(i==preorder.size() || preorder[i] >= uBound) return NULL;
        
        TreeNode *root = new TreeNode(preorder[i++]);
        
        root->left = bstBuild(preorder, i, root->val);
        root->right = bstBuild(preorder, i, uBound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //Step-1. visiting the tree in preorder.
        //Step-2. if current array value satisfy the required constraints at any place, then just place a node with value there and go to next value.
        //Fact: As we are moving in preorder fashion and try to place array values in index based order, so no need to worry about wrong placement and we only need to take uBound value.
        
        int i = 0;
        return bstBuild(preorder, i, INT_MAX) ;
    }
    //T - 3n = O(n)
    //S - O(h) = recursion stack size
};