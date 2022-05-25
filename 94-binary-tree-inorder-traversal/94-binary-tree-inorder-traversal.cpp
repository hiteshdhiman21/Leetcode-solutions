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
/*
 Recursive
class Solution {
public:
    void inorder(TreeNode *root, vector<int> &ans){
        if(root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        //Approach: Left Self Right
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    //T - O(n)
    //S - O(h) = O(n) in case of skewed trees
    
};

//Iterative
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        //Approach: Left Self Right (Use stack for simulating recursion)
        //Step-1. Use while loop and start from the root
        //Step-2. For each node push it into the stack and go to its left node.
        //Step-3. If node == NULL, set node = pop from the stack (it will directly reach to the closest     ancestor which is not printed). Then do similar steps on that node.
        //Step-4. Once stack is empty it means every node is printed along with its subtrees. hence break.
        
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        
        while(true){
            if(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }else{
                if(st.empty()) break;
                cur = st.top(); st.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        
        return ans;
    }
    //T - O(n)
    //S - O(h) = O(n) in case of skewed trees
    */

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        //Approach: Morris Traversal
        //Step-1. While cur is not empty traverse. (Fact: Always leftmost node is visited first and rightmost node is visited last)
        //Case-1: If(cur doesn't have left), Just print the cur and move to right child.
        //Case-2: If(cur have left), Go to the rightmost node int the left subtree and if its right link is NULL(it means left subtree is not visited yet), make its right link to the cur and move to the left child.
        //If its right link is pointing to the cur,(it means we came here after visiting left subtree), so just remove the link, print the cur and move to the right subtree.
        
        vector<int> ans;
        TreeNode *cur = root;
         
        while(cur){
            if(!cur->left){  //If cur doesn't have left, just print this and go to right then.
                ans.push_back(cur->val);
                cur = cur->right;
            }else{
                //Go to rightmost node in the leftsubtree and make it right link point to cur.
                TreeNode *prev = cur->left;
                while(prev->right != NULL && prev->right != cur){
                    prev = prev->right;
                }
                
                if(prev->right != cur){ //Cur is just visited once and from the top. Hence make link and visit left.
                    prev->right = cur;
                    cur = cur->left;
                }else{ //Came here after visiting whole left subtree
                    prev->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        
        return ans;
    }
    //T - O(n)
    //S - O(1)

};