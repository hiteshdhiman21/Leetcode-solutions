/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void generateParent(TreeNode *root, TreeNode* target, unordered_map<TreeNode*, TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur = q.front(); q.pop();
            if(cur->left){
                q.push(cur->left);
                parent[cur->left] = cur;
            }
            if(cur->right){
                q.push(cur->right);
                parent[cur->right] = cur;
            }
        }
    }
    
    void solve(TreeNode* target, int k, unordered_map<TreeNode*, TreeNode*>& parent, vector<int> &res){
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis; 
        q.push(target);
        vis.insert(target);
        int dist = 0;
        
        while(!q.empty()){
            
            if(dist == k){
                while(!q.empty()){
                    res.push_back(q.front()->val);
                    q.pop();
                }
            }
            
            int qSize = q.size();
            for(int i=1; i<=qSize; i++){
                TreeNode *cur = q.front();  q.pop();
                if(cur->left && !vis.count(cur->left)){
                    q.push(cur->left);
                    vis.insert(cur->left);
                } 
                if(cur->right && !vis.count(cur->right)){
                    q.push(cur->right);
                    vis.insert(cur->right);
                } 
                if(parent.count(cur)&& !vis.count(parent[cur])){
                    q.push(parent[cur]);
                    vis.insert(parent[cur]);
                } 
            }
            
            dist++;   
        }
        
        
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        generateParent(root, target, parent);
        
        vector<int> res;
        solve(target, k, parent, res);
        return res;
    }
    //T - O(n)
    //S - O(n)
};