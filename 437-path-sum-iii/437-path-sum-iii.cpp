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
    
    int cnt = 0;
    int target;
    
    void solve(TreeNode *root, unordered_map<long, int>& sumFreq, long& curSum){
        if(root == NULL) return;
        
        curSum += root->val;
        
        if(sumFreq.count(curSum-target) > 0)
            cnt += sumFreq[curSum-target];
        
        sumFreq[curSum]++; //So that upper if statement only calculates path involving atleast one node
        
        solve(root->left, sumFreq, curSum);
        solve(root->right, sumFreq, curSum);
        
        sumFreq[curSum]--;
        curSum -= root->val;               
    }
    
    int pathSum(TreeNode* root, int target) {
        //Same approach like subset sum equals k (But with tree traversal)
        unordered_map<long, int> sumFreq;
        
        this->target = target;
        long curSum = 0;
        sumFreq[0] = 1;
        
        solve(root, sumFreq, curSum);
        return cnt;
    }
    //T - O(n)
    //S - O(n)
};