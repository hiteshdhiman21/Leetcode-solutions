/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        
        Node *cloneHead = NULL;
        
        unordered_map<int, Node*> m;
        
        if(node){
            q.push(node);
            cloneHead = new Node(node->val);
            m[node->val] = cloneHead;
        }
         
        while(!q.empty()){
            Node *cur = q.front(); q.pop();
            Node *cloneCur = m[cur->val];           
            
            for(auto x:cur->neighbors){
                Node *clone;
                if(m.count(x->val)) clone = m[x->val];
                else clone = new Node(x->val);
                
                cloneCur->neighbors.push_back(clone);
                if(!m.count(x->val)){
                    q.push(x);
                    m[x->val] = clone;
                }
                
            }          
        }
        
        return cloneHead;
    }
    //T - O(V+E)
    //S - O(V)
};