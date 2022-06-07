// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> weight(V, 1e8);
        vector<int> parent(V, -1);
        vector<bool> takenInMST(V, false);
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        weight[0] = 0;
        pq.push({0, 0});
        
        int ans = 0;
        
        while(!pq.empty()){
            while(!pq.empty() && takenInMST[pq.top().second] == true) pq.pop();
            if(pq.empty()) break;
            
            int u = pq.top().second; pq.pop();
            takenInMST[u] = true;
            ans += weight[u];
            
            for(auto& __:adj[u]){
                int v = __[0];
                int w = __[1];
                
                if(!takenInMST[v] && weight[v] > w){
                    weight[v] = w;
                    parent[v] = u;
                    pq.push({weight[v], v});
                }
            }
        
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends