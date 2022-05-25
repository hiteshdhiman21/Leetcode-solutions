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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        //For each line storing nodes in each level in increasing order
        //We can use any type of traversal as we are storing in line sorted, level sorted and values sorted order.
        map<int, map<int, multiset<int>>> lineLevelNodes;
        queue<pair<TreeNode*,  pair<int, int>>> q;
        
        if(root != NULL) q.push({root, {0, 0}});
        
        while(!q.empty()){
            TreeNode *cur = q.front().first;
            int line = q.front().second.first, level = q.front().second.second;
            q.pop();
            lineLevelNodes[line][level].insert(cur->val);
            
            if(cur->left) q.push({cur->left, {line-1, level+1}});
            if(cur->right) q.push({cur->right, {line+1, level+1}});
        }
        
        vector<vector<int>> ans;
        for(auto _:lineLevelNodes){ //each line(column) -> starting from leftmost line
            ans.push_back({}); 
            for(auto __:_.second){ //each level(row) -> starting from top level
                ans.back().insert(ans.back().end(), __.second.begin(), __.second.end()); //ascending order in same row
            }
        }
        
        return ans;
    }
    //T - O(N*logN*logN*logN)
    //S - O(n)
};