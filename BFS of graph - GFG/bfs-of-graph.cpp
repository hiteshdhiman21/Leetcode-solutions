// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    void bfs(int sv, vector<int> adj[], vector<bool> &visited, vector<int>& bfsTraversal){
        queue<int> q;
        q.push(sv);
        visited[sv] = true;
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            bfsTraversal.push_back(cur);
            
            for(int x: adj[cur]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        //This question is incomplete there on GFG, But i have done full approach;
        vector<bool> visited(V, false);
        vector<int> bfsTraversal;
        
        
       
        bfs(0, adj, visited, bfsTraversal);
        
        
        return bfsTraversal;
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
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends