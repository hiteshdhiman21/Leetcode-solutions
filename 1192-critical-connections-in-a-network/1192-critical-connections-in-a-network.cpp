class Solution {
public:
    //
    //curIdNo -> determines order of visiting nodes. id[node2] < id[node1] implies that node2 is visited before node1.
    //lowIdVis[i] -> determines which is the lowest id node visited by node i.
    //If node i is able to visit a node x with id[x] < id[parent of i], Then it means after removing this edge also, it will be able to visit its parent via some path containing node x in between.
    
    
    void tarjans(int cur,  int parent, int& curIdNo, vector<int>& id, vector<int>& lowIdVis, vector<vector<int>> &adj, int n,  vector<vector<int>> &ans){
        id[cur] = curIdNo++; //Assigning curIdNo to it and incrementing curIdNo, so that node visited later will get larger curId
        lowIdVis[cur] = id[cur];
        
        for(int x:adj[cur]){
            if(x==parent) continue;
            
            if(id[x] == INT_MAX){
                tarjans(x, cur, curIdNo, id, lowIdVis, adj, n, ans);
                 if(id[cur] < lowIdVis[x]){ //It means after removing this cur->x edge, x will not be able to reach to nodes 
                                            //which are already visited before cur and x will also not able to visit cur.
                                            //Hence it is a critical edge.
                ans.push_back({cur, x});
                }
            }
            
            lowIdVis[cur] = min(lowIdVis[cur], lowIdVis[x]);
            
            
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //vector<int> id(n);
        vector<int> lowIdVis(n, INT_MAX);
        vector<int> id(n, INT_MAX);
        
        //Storing edges in adjacency list form.
        vector<vector<int>> adj(n);
        for(int i=0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        
        vector<vector<int>> ans;
        int curIdNo = 0;
        tarjans(0, -1, curIdNo, id, lowIdVis, adj, n, ans);
        //for(auto x:low) cout << x << " " ;
        //cout << endl;
        
        return ans;
    }
};