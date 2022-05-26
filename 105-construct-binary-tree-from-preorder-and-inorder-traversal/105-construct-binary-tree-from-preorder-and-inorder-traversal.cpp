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

    
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap){
        if(preStart > preEnd) return NULL;
        
        int rootData = preorder[preStart]; //Root = first element of preorder
        int inRoot = inMap[rootData]; //Root index in inorder
        TreeNode *root = new TreeNode(rootData); 
        
        int preS1 = preStart+1, inS1 = inStart, inE1 = inRoot-1, preE1 = preS1+inE1-inS1; //preE-preS = inE-inS
        int preS2 = preE1+1, inS2 = inRoot+1, inE2 = inEnd, preE2 = preEnd;
        
        root->left = buildTree(preorder, preS1, preE1, inorder, inS1, inE1, inMap);
        root->right = buildTree(preorder, preS2, preE2, inorder, inS2, inE2, inMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap; //Using map for efficient retrieval of indices for different values
        for(int i=0; i<inorder.size(); i++) inMap[inorder[i]] = i;
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    }
    //T - O(n)
    //S - O(n) for storing inorder values vs indexes in hashmap
    //T - O(n^2) and S - O(1) if find index at every node without using hashmap
};