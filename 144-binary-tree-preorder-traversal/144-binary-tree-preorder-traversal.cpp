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
    vector<int> preorderTraversal(TreeNode* root) {
        
        //Similar to inorder.
        //Here if cur is not null we first print it and then go to the left child. else, cur = st.pop() and cur = cur->right
        vector<int> ans;
        
        TreeNode* cur = root;
        stack<TreeNode*> st;
        
        while(true){           
            if(cur != NULL){
                ans.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }else{
                if(st.empty()) break;
                cur = st.top(); st.pop();
                cur = cur->right;
            }
        }
        
        return ans;
    }
    //T - O(n)
    //S - O(h)  = O(n) in case of skewed trees.
};