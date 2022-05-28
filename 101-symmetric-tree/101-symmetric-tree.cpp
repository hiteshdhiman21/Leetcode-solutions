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
    
    
    bool isSymmetric(TreeNode* root) {
        //Mirror-> left(right) subtree of every node of tree1(root->left) should mirror to right(left) subtree of corresponding node of tree2(root->right). which means nodes of both trees should coincide when visited in Mirror(opposite one LR and other RL) order.
        //Step-1. Traverse nodes of both the tree in opp order. if node1->val != node2->val || (both doesn't have same no. of NOT NULL connections). Then return false. 
        //Step-2. After one tree is traversed fully, check if other is fully traversed or Not.
        //Step-3. If not return false, else return true.
        queue<TreeNode*> q1, q2;
        if(root && root->left) q1.push(root);
        if(root && root->right) q2.push(root);
        
        while(!q1.empty() && !q2.empty()){
            TreeNode *cur1 = q1.front(); q1.pop();
            TreeNode *cur2 = q2.front(); q2.pop();
            if(cur1->val != cur2->val) return false;
            
            if(cur1->left && !cur2->right || cur1->right && !cur2->left) return false;
            if(cur1->left) q1.push(cur1->left);
            if(cur1->right) q1.push(cur1->right);
            
            if(cur2->right) q2.push(cur2->right);
            if(cur2->left) q2.push(cur2->left);
        }
        
        if(!q1.empty()||!q2.empty()) return false;
        return true;
    }
    //T - O(n)
    //S - O(n) (2 stack with total just n space)
};