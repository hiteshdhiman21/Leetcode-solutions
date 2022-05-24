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
/* Recursive
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
    
};*/

//Iterative
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        //Approach: Left Self Right (Use stack for simulating recursion)
        //Step-1. Use while loop and start from the root
        //Step-2. For each node push it into the stack and go to its left node.
        //Step-3. If node == NULL, set node = pop from the stack (it will directly reach to the closest ancestor which is not printed). Then do similar steps on that node.
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
    
};