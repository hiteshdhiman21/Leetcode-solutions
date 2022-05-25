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
    
    //first-> will store max depth, second-> will store max diameter.
    //For each node we will calculate max depth and max diameter passing through it.
    //final ans = max diameter of all the nodes.
    pair<int, int> findDiameter(TreeNode* root){
        if(root == NULL)  return make_pair(0, 0);
        
        pair<int, int> ans;
        pair<int, int> leftAns = findDiameter(root->left);
        pair<int, int> rightAns = findDiameter(root->right);
        ans.first = max(leftAns.first+1, rightAns.first+1);
        ans.second = max(leftAns.first+rightAns.first, max(leftAns.second, rightAns.second));
        return ans;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        //Use DP to return maxDiameter from left subtree, right subtree and current tree node
        return findDiameter(root).second;
    }
    //T - O(n)
    //S - O(h)
};