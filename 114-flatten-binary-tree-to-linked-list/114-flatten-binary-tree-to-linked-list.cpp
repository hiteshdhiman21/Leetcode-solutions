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
    
    /*pair<TreeNode*, TreeNode*> flat(TreeNode *root){
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
    }*/
    
    /*TreeNode *prev = NULL;
    void flatten(TreeNode *root){
        //Just use revers Postorder
        //Intuition: In this way, First:  the node visited first in left subtree postorder will connect to the node visited last in right subtree postorder. Second: the root will connect to the node visited last in left subtree postorder.
        
        if(root == NULL) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = NULL;
        
        prev = root;
    }
    //T - O(n)
    //S - O(n)*/
    
    /*
    void flatten(TreeNode *root){
        //Just use revers Postorder
        //Intuition: In this way, First:  Every root will connect to its left or right child if presents. Second: the rightmost node on left subtree will be visited last of whole left subtree and will connect to the right child of parent of left subtree.
        
        stack<TreeNode*> st;
        if(root)
        st.push(root);
        while(!st.empty()){
            TreeNode *cur = st.top(); st.pop();
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
            if(!st.empty())
            cur->right = st.top();
            cur->left = NULL;
        }
    }
    //T - O(n)
    //S - O(n)*/
    
    void flatten(TreeNode *root){
        //Best approach
        //Intuition: Use Morris traveral: For every root node, If left node present, connect rightmost node of its left subtree to its(root's) right and update root->right = root->left, root->left = NULL
        
        TreeNode *cur = root;
        while(cur){
            if(cur->left){
                TreeNode *prev = cur->left;
                while(prev-> right) prev = prev->right;
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            
            cur = cur->right;
        }
        
    }
    //T - O(n)
    //S - O(1)
    
    

};