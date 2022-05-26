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
    int findIndex(vector<int>& v, int s, int e, int val){
        for(int i=s; i<=e; i++){
            if(v[i] == val) return i;
        }
        return -1;
    }
    
    TreeNode* buildTree(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2){
        if(s1>e1) return NULL;
        int rootData = preorder[s1];
        TreeNode *root = new TreeNode(rootData);
        int ns1 = s1+1;
        int ne2 = findIndex(inorder, s2, e2, rootData)-1;
        int ns2 = s2;
        int ne1 = ne2-ns2+ns1;
        root->left = buildTree(preorder, ns1, ne1, inorder, ns2, ne2);
        root->right = buildTree(preorder, ne1+1, e1, inorder, ne2+2, e2);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};