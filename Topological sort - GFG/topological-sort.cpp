// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //Intuition: We will first push all the nodes with inDegree[0] and then we will push any
	    //      vertex only whose dependant upon vertices has already been pushed.
	    //In this way every v vertex with some edge u->v, will be pushed after u.
	    //Kahn's algorithm
	    vector<int> inDegree(V);
	    for(int u=0; u<V; u++){
	        for(int v:adj[u]) inDegree[v]++;
	    }
	    
	    queue<int> q;
	    for(int i=0; i<V; i++){
	        if(inDegree[i] == 0) q.push(i);
	    }
	 
	    vector<int> topo;
	    while(!q.empty()){
	        int cur = q.front(); q.pop();
	        topo.push_back(cur);
	        for(int x:adj[cur]){
	            inDegree[x]--;
	            if(inDegree[x] == 0) q.push(x);
	        }
	    }
	    
	    return topo;
	}
	//T - O(V+E)
	//S - O(V)
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends