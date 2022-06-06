// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {   
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(V, 1e6+5);
        distTo[S] = 0;
        pq.push({0, S});
        
        for(int i=1; i<V; i++){
            
            while(pq.top().first > distTo[pq.top().second]) pq.pop();
            
            int curDist = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            
            for(auto x:adj[cur]){
                if(distTo[x[0]] > curDist + x[1]){
                    distTo[x[0]] = curDist+ x[1];
                    pq.push({distTo[x[0]], x[0]});
                }
            }
        }
        
        return distTo;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends