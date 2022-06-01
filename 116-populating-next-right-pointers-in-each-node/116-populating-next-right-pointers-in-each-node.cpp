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
       //Given: All Nodes can have 0, 1(any), or 2 childs. So it is not possible to do it in leetcode way.
    //So, we will use level order traversal. 2 ways: Less optimal using queue and most optimal using no space.
    //Assumptions: startNode is pointing at the startNode of upper level which are already connected. Using upper level nodes we are connecting lower level nodes. prev is pointing to current level nodes. 
    //Step-1. Initialise startNode = root. Because there is only one node at that level.
    //Step-2. Now start connecting lower level nodes using it. Use prev to denote which node's next we have to connect now.
    //Step-3. Start traversing upper level nodes using startNode for every level.
    //Step-4. If startNode->left != NULL connect prev->next to it if prev is valid, else assign this first node to prev.
    //    If startNode->right != NULL connect prev->next to it if prev is valid, else assign this first node to prev.
    //Step-5. After visiting all the nodes at one level and connecting its below nodes, update startNode = first node of below nodes for the next iteration.
    
   Node* startNode = root;
    
    while(startNode != NULL){
        Node * prev = NULL;
        Node * nextStartNode = NULL;
        
        while(startNode){
            if(!prev){ //If prev == NULL, assign this first node of this level to prev
                prev = startNode->left;
                nextStartNode = prev;
            }else if(startNode->left && startNode->left != prev){
                //Connect prev->next to this node and update prev = this node for further connecting it to others.
                prev->next = startNode->left;
                prev = prev->next;
            }
            if(!prev){ //If prev == NULL, assign this first node of this level to prev
                prev = startNode->right;
                nextStartNode = prev;
            }else if(startNode->right && startNode->right != prev){
                //Connect prev->next to this node and update prev = this node for further connecting it to others.
                prev->next = startNode->right;
                prev = prev->next;
            }
            
            startNode = startNode->next;
        }
        
        startNode = nextStartNode;
    
    }
   
        return root;
    
    }
    //T-O(n)
    //S-O(1)
};