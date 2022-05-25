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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //Use queue with BFS strategy for level-order traveral
        
        queue<TreeNode*> q;
        
        if(root!=NULL) q.push(root);
        vector<vector<int>> ans;
        
        //Way to traverse each level separately
        while(!q.empty()){
            int size = q.size(); //No. of nodes in the current level
            ans.push_back({});
            //Only visit the current level nodes which are pushed earler New nodes pushed will not be visited.
            for(int i=0; i<size; i++){ 
                TreeNode *cur = q.front(); q.pop();
                ans.back().push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        
        return ans;      
    }
    //T - O(n)
    //S - O(n);
};