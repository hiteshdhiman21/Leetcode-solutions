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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        //Step-1. Visit the elements and push into the queue in the exact same order as level order. Technique of visiting only same level nodes in a particular iteration.
        //Step-2. Just change the places of insertion in the ans vector. i.e., if dir = LR, insert in ans from left to right. Else insert in ans from right to left.(Don't change order of visiting element, just change the order of insertion of the elements)
        /*LR -> 1 2 3               RL -> 1 2 3
                1                             1
                1 2                         2 1
                1 2 3                     3 2 1  */
                            
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        bool LR = true;
        if(root) q.push(root);
        
        while(!q.empty()){
            
            ans.push_back({});
            int size = q.size();
            ans.back().resize(size);
            
            for(int i=0; i<size; i++){
                TreeNode *cur = q.front(); q.pop();
                int val = cur->val;
                
                //Order to insert in ans. LR -> 0 1 2 3 4,  RL -> 4 3 2 1 0
                    
                int index = (LR)?i:size-i-1; 
                ans.back()[index] = val;
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                
            }
            LR = !LR;
        }
        
        return ans;
    }
    //T - O(n)
    //S - O(1)
};