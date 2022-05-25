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
    //Find width on the same level only
    //Warning: Beware of Integer oveflow (testcases)
    //For this used trick of starting every level with node number 0.(Refer to code) 2*(i-min_i) and 2*(i-min_i)+1 for childs
    int widthOfBinaryTree(TreeNode* root) {
        
        //Approach: Traverse the tree in the level order and for each level find width = lastNodeNo-firstNodeNo+1. Use 2*(i-min_i) and 2*(i-min_i)+1 for generating numbers for childs
        queue<pair<TreeNode*, long>> q;
        if(root != NULL) q.push({root,  0});
        int max_width = 0;
        int leftNodeNo = 0, rightNodeNo = 0;
        
        //Way to travel the same level nodes only at a time
        while(!q.empty()){
            int size = q.size();
         
            for(int i=0; i<size; i++){ 
                TreeNode *cur = q.front().first;
                long nodeNo = q.front().second; q.pop();
            
                if(i==0) leftNodeNo = nodeNo;
                if(i == size-1) rightNodeNo = nodeNo;
                
                nodeNo -= leftNodeNo;
                if(cur->left) q.push({cur->left, 2*(long)nodeNo});
                if(cur->right) q.push({cur->right, 2*(long)nodeNo+1});
                
            }
            max_width = max(max_width, rightNodeNo-leftNodeNo+1);
        }
        
        return max_width;
    }
    //T - O(n)
    //S - O(1)
};