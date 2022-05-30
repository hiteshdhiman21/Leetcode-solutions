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
    
    pair<TreeNode*, TreeNode*> flat(TreeNode *root){
        if(root == NULL || (!root->left && !root->right)) return {root, root};

        
        pair<TreeNode*, TreeNode*> left = flat(root->left);
        pair<TreeNode*, TreeNode*> right = flat(root->right);
        
        if(left.first)
        cout << root->val <<  " :  " << left.first->val << " " << left.second->val << endl;
        if(right.first)
        cout << root->val <<  " :  " << right.first->val << " " << right.second->val << endl;
        
        TreeNode *curSecond = NULL;
        if(left.first && left.second){
            root->right = left.first;
            left.second->right = right.first;
        }
        
        if(right.second) curSecond = right.second;
        else curSecond = left.second;
        root->left = NULL;
        
        return {root, curSecond};
    }
    
    void flatten(TreeNode* root) {
        flat(root);
    }
};