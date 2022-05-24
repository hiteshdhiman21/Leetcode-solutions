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
};