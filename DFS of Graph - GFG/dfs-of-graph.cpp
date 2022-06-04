// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    void dfs(int sv, vector<int> adj[], vector<bool> &visited, vector<int> &dfsTraversal){
        dfsTraversal.push_back(sv);
        visited[sv] = true;
        for(int x:adj[sv]){
            if(!visited[x]) dfs(x, adj, visited, dfsTraversal);
        }    
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        //vector<int> adj[] refers to an array of vectors
        vector<bool> visited(V, false);
        vector<int> dfsTraversal;
        
        for(int i =0; i<V; i++){
            if(!visited[i])
            dfs(i, adj, visited, dfsTraversal);
        }
        
        return dfsTraversal;
    }
    //T - O(V+E)
    //S - O(V)
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends