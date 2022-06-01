/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //Given: Every node have exactly 0 or 2 childs.
        if(root==NULL) return root;
        
        //Connect the left child's next to right child
        if(root->left) root->left->next = root->right; 
        
        //Connect the right childs'next to root's right brother's left.
        if(root->right && root->next) root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
        return root;
    }
    //T-O(n)
    //S-O(1)
};