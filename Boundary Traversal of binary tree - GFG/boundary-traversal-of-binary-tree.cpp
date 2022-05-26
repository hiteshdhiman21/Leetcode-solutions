// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









 // } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

    bool isLeaf(Node *root){
        return !root->left && !root->right;
    }

    void addLeafNodes(Node* root, vector<int>& ans){
        if(root == NULL) return;
        if(isLeaf(root)){
            ans.push_back(root->data); return;
        }

        addLeafNodes(root->left, ans);
        addLeafNodes(root->right, ans);
    }

    void addLeftBoundary(Node* root, vector<int> &ans){
        Node *cur = root;
        while(cur && !isLeaf(cur)){
            ans.push_back(cur->data);
            if(cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    void addRightBoundary(Node* root, vector<int> &ans){
        Node *cur = root;
        vector<int> temp;
        while(cur && !isLeaf(cur)){
            temp.push_back(cur->data);
            if(cur->right) cur = cur->right;
            else cur = cur->left;
        }
        ans.insert(ans.end(),temp.rbegin(), temp.rend()); //Adding temp vector in reverse order
    }
    
    vector <int> boundary(Node *root)
    {
        //Step-1. If root == NULL, return empty vector. Else,
        //Step-2. If root != leaf, push root into ans vector. Else, it would automaticaly be added by step-4.
        //Step-3. Add left boundary excluding the root and the leaf nodes in Top-to-bottom order.
        //Step-4. Add leaf nodes only in left-to-right order.
        //Step-5. Add right boundary excluding the root and the leaf nodes in Bottom-to-top order using reverse vector.
        
        vector<int> ans;
        
        if(root == NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        
        addLeftBoundary(root->left, ans); //Left boundary excluding root and leaf nodes
       
        addLeafNodes(root, ans); //Adding only leaf nodes from left to right.
       
        addRightBoundary(root->right, ans); //Right boundary excluding root and leaf nodes in bottom-to-to order
      
        return ans;
    }
    //T - O(n)
    //S - O(h)
};

// { Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends