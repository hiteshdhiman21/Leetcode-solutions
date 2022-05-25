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
/*class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //using 2 stacks. Take top element from stack1 and transfer it to stack 2.
        //Transferring children of that element into stack1.
        //Then take new element from stack1 and do the same for every iteration while stack1 is not empty/
        //Just print the element of stack2 in usual LIFO fashion.
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<TreeNode*> st1, st2;
        st1.push(root);
        
        while(!st1.empty()){
            TreeNode *cur = st1.top();
            st1.pop();
            st2.push(cur);
            
            if(cur->left != NULL) st1.push(cur->left);
            if(cur->right != NULL) st1.push(cur->right);
        }
        
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        
        return ans;
    }
    //T - O(n)
    //S - O(1)
};*/


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //Uses cur to explore downward
        //Uses temp to go to right child and its ancestors.
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        
        while(cur != NULL || !st.empty()){ 
            if(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }else{
                TreeNode *temp = st.top()->right;
                if(temp==NULL){//Here visiting all the ancestors whose right child has been visited
                    temp = st.top(); st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){ //temp is visited and so temp == st.top()->right means st.top()->right child is visited. Hence now visiting st.top().
                        temp = st.top(); st.pop();
                        ans.push_back(temp->val);
                    }
                }else{//Visiting right child and its both childrens in postorder fashion
                    cur = temp;
                }
            }  
        } 
        return ans;
    }
};