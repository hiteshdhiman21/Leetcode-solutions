class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto _: connections){
            adj[_[0]].push_back(_[1]);
            adj[_[1]].push_back(-_[0]);
        }
        
        vector<bool> vis(n);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        
        int res = 0;
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            
            for(int x : adj[cur]){
                if(!vis[abs(x)]){
                    if(x > 0) res++; 
                    q.push(abs(x));
                    vis[abs(x)] = true;
                }
                    
            }
        }
        
        return res;
    }
    //T - O(n)
    //S - O(1)
};