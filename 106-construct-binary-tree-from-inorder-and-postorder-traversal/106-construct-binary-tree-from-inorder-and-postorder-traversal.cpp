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
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& inMap){
        if(inStart > inEnd) return NULL;
        
        int rootData = postorder[postEnd]; //Root = first element of preorder
        int inRoot = inMap[rootData]; //Root index in inorder
        TreeNode *root = new TreeNode(rootData); //Create root
        
        int postS1 = postStart, inS1 = inStart, inE1 = inRoot-1, postE1 = postS1+inE1-inS1;//postE-postS = inE-inS
        int postS2 = postE1+1, inS2 = inRoot+1, inE2 = inEnd, postE2 = postS2+inE2-inS2; 
        
        root->left = buildTree(inorder, inS1, inE1, postorder, postS1, postE1, inMap); //Join left subtree
        root->right = buildTree(inorder, inS2, inE2, postorder, postS2, postE2, inMap); //Join right subtree
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //Intuition: Believe that recursion wil create correct subtrees and will return their roots.
        //Step-1. Find root from postorder and find index of root in inorder(inRoot). Create root.
        //Step-2. Inorder before the inRoot is inorder of left subtree and after inRoot is of right subtree.
        //Step-3. Postorder of leftsubtree will be before of right subtree which will end at second last Index.
        //Step-4. Using above, ask recursion to create left and right subtrees and join them with the root.
        unordered_map<int, int> inMap; //Using map for efficient retrieval of indices for different values
        for(int i=0; i<inorder.size(); i++) inMap[inorder[i]] = i;
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
    }
    //T - O(n)
    //S - O(n) for storing inorder values vs indexes in hashmap
    //T - O(n^2) and S - O(1) if find index at every node without using hashmap
};