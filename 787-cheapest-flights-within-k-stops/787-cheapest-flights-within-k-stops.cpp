class Solution {
public:
    
    void print(vector<int> &dist){
        for(int &x: dist)
            cout << x << " ";
        cout << endl;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      /*Approach: BellMann Ford algo
        Relax all the edges k+1 times.
        In ith iteration path of dist <=i from source will get optimize fully.
        */
        
        vector<int> dist(n, INT_MAX);
           
        dist[src] = 0;
        for(int i = 1; i<=k+1; i++){
            vector<int> prevDist(dist);
            for(auto __: flights){
                int u = __[0], v = __[1], wt = __[2];
                if(prevDist[u] != INT_MAX && prevDist[u]+wt < dist[v]){
                    dist[v] = prevDist[u]+wt;
                }
                    
            }
            
        }
        
        return dist[dst]!=INT_MAX?dist[dst]:-1;        
    }
    //T - O(Ek)
    //S - O(V)
};