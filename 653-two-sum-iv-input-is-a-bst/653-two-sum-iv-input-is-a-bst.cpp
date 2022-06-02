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

class BSTIterator {
private:
    stack<TreeNode*> st;
    bool reverse = false; //False means next iterator, True means before iterator
    //Next iterator - inorder, Before iterator - reverse inorder
    
    void pushAll(TreeNode *root){
        while(root){
            st.push(root);
            root = (reverse)?root->right:root->left; 
        }
    }
    
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        this->reverse = isReverse;
        pushAll(root);
    }
    
    int next() { 
        //Next -> we will push all the lefts of the right tree after printing current root node.
        //Before -> we will push all the rights of the left tree after printing current root node.
        TreeNode *tmp = st.top(); st.pop();
        (this->reverse)?pushAll(tmp->left):pushAll(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    //T - O(n) for all functions
    //S - O(h)
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        
        //Approach: Solve it like 2 sum using 2 pointers on sorted array. We will use iterators for this.
        //L pointer will be served by next iterator and R pointer will be served by before iterator.
        //Next iterator - inorder(ascending order).  Before iterator - reverse inorder(descending order)
        
        BSTIterator* l = new BSTIterator(root, false);
        BSTIterator* r = new BSTIterator(root, true);
        
        int lv = l->next();
        int rv = r->next();
        
        while(lv<rv){
            if(lv+rv < k) lv = l->next();
            else if(lv+rv > k) rv = r->next();
            else return true;
        }
        
        return false;
    }
    //T - O(n)
    //S - O(h)
};