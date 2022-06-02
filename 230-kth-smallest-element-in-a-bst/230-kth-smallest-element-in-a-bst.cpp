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
    
    
    
    int kthSmallest(TreeNode* root, int k) {
        //Just doing Morris inorder traversal and maintaining a cur Node no. pointer
        //As inorder traveral visits the node in sorted order, the kth node no have kth smallest value.
        
        int curNo = 0;
        TreeNode *cur = root;
        int ans = -1;
         
        while(cur){
            if(!cur->left){
                curNo++;
                if(curNo == k) ans = cur->val;
                cur = cur->right;
            }else{
                TreeNode *prev = cur->left;
                while(prev->right != NULL && prev->right != cur){
                    prev = prev->right;
                }
                
                if(prev->right != cur){ 
                    prev->right = cur;
                    cur = cur->left;
                }else{
                    prev->right = NULL;
                    curNo++;
                    if(curNo == k) ans = cur->val;
                    cur = cur->right;
                }
            }
        }
        
        return ans; 
    }
    //T - O(n) amortized
    //S - O(1)
};