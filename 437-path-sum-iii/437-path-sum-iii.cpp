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
    unordered_map<long, int> solve(TreeNode *root, int target, int& cnt){
        if(root==NULL)
            return {{}};
        
        unordered_map<long, int> myFreq;
        unordered_map<long, int> leftFreq = solve(root->left, target, cnt);
        for(auto &__: leftFreq){
            if(__.first+root->val == target)
                cnt += __.second;
            myFreq[__.first+root->val] = __.second;
        }
        
        unordered_map<long, int> rightFreq = solve(root->right, target, cnt);
        for(auto & __: rightFreq){
            if(__.first+root->val == target)
                cnt += __.second;
             myFreq[__.first+root->val] += __.second;
        }
        
        if(target == root->val)
            cnt++;
        
        myFreq[root->val]++;
        return myFreq;
    }
    
    int pathSum(TreeNode* root, int target) {
        int cnt = 0;
        solve(root, target, cnt);
        return cnt;
    }
};