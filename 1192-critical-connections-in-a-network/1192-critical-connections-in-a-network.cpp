class Solution {
public:
    
    void tarjans(int cur,  int& curId, vector<int>& low, vector<vector<int>> &adj, int n, int last, vector<vector<int>> &ans){
        //id[cur] = ++curId;
        low[cur] = curId++;
        //cout << cur << " " << low[cur] << endl;
        
        int lowCurup = low[cur];
        for(int x:adj[cur]){
            if(x==last) continue;
            
            if(low[x] == INT_MAX){
                tarjans(x, curId, low, adj, n, cur, ans);
                lowCurup = min(lowCurup, low[x]);
                 if(low[cur] < low[x]){
                ans.push_back({cur, x});
                }
            }else{
                lowCurup = min(lowCurup, low[x]);
            }
            
            
        }
        low[cur] = lowCurup;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //vector<int> id(n);
        vector<int> low(n, INT_MAX);
        
        
        vector<vector<int>> adj(n);
        for(int i=0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        
        vector<vector<int>> ans;
        int curId = 0;
        tarjans(0, curId, low,  adj, n, -1, ans);
        //for(auto x:low) cout << x << " " ;
        //cout << endl;
        
        return ans;
    }
};