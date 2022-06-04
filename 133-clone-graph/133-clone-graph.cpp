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
        //Step-1. Just do Normal BFS and before pushing any node into the queue just make its clone(if the clone is not present) and do mapping of {original, clone} nodes.
        //Step-2. For every node o, if it have o1, o2, o3 neighbours. make mp[o] have mp[o1], mp[o2], mp[o3] as neigbours.
        //Step-3. If any node is visited before or is pushed into the queue anytime before. It means that its clone is already made and mapped and hence no need to make it again. i.e, clone is created at time of marking visiting that node.
        //Step-4. return mp[node]
        queue<Node*> q;        
        unordered_map<Node*, Node*> mp;
        
        if(node){
            q.push(node);
            mp[node] = new Node(node->val);
        }
         
        while(!q.empty()){
            Node *cur = q.front(); q.pop();          
            
            for(auto x:cur->neighbors){
                if(!mp.count(x)){
                    mp[x] = new Node(x->val);
                    q.push(x);
                }
                
                mp[cur]->neighbors.push_back(mp[x]);
            }          
        }
        
        return mp[node];
    }
    
    //T - O(V+E)
    //S - O(V)
};