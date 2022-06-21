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
    
    void addSubTree(TreeNode *root, int dist, vector<int> &res){
        
        if(root == NULL || dist < 0){
            return;
        }else if(dist == 0){
            res.push_back(root->val);
            return;
        }
        
        addSubTree(root->left, dist-1, res);
        addSubTree(root->right, dist-1, res);      
        
    }
    
    int dfs(TreeNode* root, TreeNode* target, int k, vector<int> &res){
        if(root == NULL)
            return -1;
        else if(root == target){
            addSubTree(root->left, k-1, res);
            addSubTree(root->right, k-1, res);
            return 0;
        }
            
        
        int dist = -1;
        int dist1 = dfs(root->left, target, k, res);
        if(dist1 != -1){
            dist = dist1+1;
            addSubTree(root->right, k-dist-1, res);
            if(dist == k)
                res.push_back(root->val);
        }else{
            int dist2 = dfs(root->right, target, k, res);
            if(dist2 != -1){
                dist = dist2+1;
                addSubTree(root->left, k-dist-1, res);
                if(dist == k)
                    res.push_back(root->val);
            } 
        }
        
        return dist;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      /*Approach: DFS (Use 1 function to find Dist of target and 1 to add nodes at a distance k)
        DFS:
        Step-1. Call DFS on left child. If node found on left side with distance = dist. If dist < k Then call addSubtree on right child with distance = k-dist-1. Else if dist == k. Add current node to res. 
        Step-2. If node not found on left side. Then call dfs on right side similary.
        Step-3. If current node == target. Then call addSubtree on its left and right childs with dist = k-1.
        Step-4. Add subtree: It will only add the nodes at a given distance from the root node.*/
        
        if(k==0)
            return {target->val};
        
        vector<int> res;
        dfs(root, target, k, res);
        return res;
    }
    //T - O(n)
    //S - O(n)
};