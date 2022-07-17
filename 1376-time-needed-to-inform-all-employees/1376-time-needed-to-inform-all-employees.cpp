class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        
        for(int i=0; i<n; i++){
            if(i != headID)
            adj[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        vector<bool> vis(n);
        vis[headID] = true;
        q.push({headID, 0});
        
        int time = 0;
        while(!q.empty()){
            int qSize = q.size(); 
            for(int i=0; i<qSize; i++){
                auto [cur, curTime] = q.front(); q.pop();
                time = max(time, curTime);
                for(int x: adj[cur]){
                    if(!vis[x])
                        q.push({x, curTime+informTime[cur]});
                }
            }
            
            if(q.empty()) break;
        }
        
        return time;
    
    }
};