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
        //Greedy algorithm:
        //Step-1. Push the Source node into priority queue with dist 0.
        //Step-2. While q is not empty, take out the min dist node from the q. (As, its distance now
        //          can't be minimized by other nodes. And it can minimize others distance). 
        //Step-3. Compare the original dist of its neighbours with or without it inclusion. If
        //        with its inclusion the distance is less, then update it and push the new dist
        //        into the queue.
        //Step-4. Finally return the minDist vector.
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(V, 1e6+5);
        distTo[S] = 0;
        pq.push({0, S});
         
        //Used pq to find min distanced nodes out of the remaining nodes. We can also use find MinVertex
        //function as in CN course.
        while(!pq.empty()){       
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
    //T - O(V*V)
    //S - O(V)
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