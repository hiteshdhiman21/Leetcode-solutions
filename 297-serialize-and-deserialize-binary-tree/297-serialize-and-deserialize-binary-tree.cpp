/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //Coverting the tree into level order traversal form
        //Also pushing the null child into the queue
        //Not exploring the null child's subtrees
        if(root == NULL) return "";
        
        queue<TreeNode*> q;
        q.push(root);
        
        string res = "";
        
        while(!q.empty()){
            TreeNode *cur = q.front(); q.pop();
            if(cur == NULL) res.append("# ");
            else{
                res.append(to_string(cur->val) + " ");
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //Using level order traversal string to make tree.
        //Not pushing the null child into the queue. Just ignoring the null child.
        //Not exploring the null child's subtrees
        
        if(data.size() == 0) return NULL;
        
        stringstream s(data);
        string curStr;
        getline(s, curStr, ' ');
        TreeNode *root = new TreeNode(stoi(curStr));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode *cur = q.front(); q.pop();
            
            getline(s, curStr, ' ');
            if(curStr == "#"){
                cur->left = NULL;
            }else{
                TreeNode* left = new TreeNode(stoi(curStr));
                cur->left = left;
                q.push(left);
            }
            
            getline(s, curStr, ' ');
            if(curStr == "#"){
                cur->right = NULL;
            }else{
                TreeNode* right = new TreeNode(stoi(curStr));
                cur->right = right;
                q.push(right);
            }
        }
        
        return root;
    }
    //T - O(n)
    //S - O(n)
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));