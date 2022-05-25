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
    vector<int> preorderTraversal(TreeNode* root) {
        //Approach: Morris Traversal
        //Step-1. While cur is not empty traverse. (Fact: Always leftmost node is visited first and rightmost node is visited last)
        //Case-1: If(cur doesn't have left), Just print the cur and move to right child.
        //Case-2: If(cur have left), Go to the rightmost node in the left subtree and if its right link is NULL(it means left subtree is not visited yet), make its right link to the cur, print cur and move to the left child.
        //If its right link is pointing to the cur,(it means we came here after visiting left subtree), so just remove the link, and move to the right subtree.
        
        vector<int> ans;
        TreeNode *cur = root;
         
        while(cur){
            if(!cur->left){  //If cur doesn't have left, just print this and go to right then.
                ans.push_back(cur->val);
                cur = cur->right;
            }else{
                //Go to rightmost node in the leftsubtree and make it right link point to cur.
                TreeNode *prev = cur->left;
                while(prev->right != NULL && prev->right != cur){
                    prev = prev->right;
                }
                
                if(prev->right != cur){ //Cur is just visited once and from the top. Hence make link, print cur and visit left.
                    prev->right = cur;
                    ans.push_back(cur->val);
                    cur = cur->left;
                }else{ //Came here after visiting whole left subtree. Hence remove link.
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
    //T - O(n) amortized
    //S - O(1)
};