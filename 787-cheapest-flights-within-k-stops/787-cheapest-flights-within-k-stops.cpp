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
        Modification: We will calculate ith level distances using (<= i-1)th level distances
        i.e. We will use prevDist[] = dist[] vector for distances calculated using i-1 stops from source and now we will calculate dist[] using prevDist involving i-1 stops and introducing a new stop.
        Step-1. Iterate for k+1 times to include/not include k stops in between.
        Step-2. Copy prev level dist vector in prevDist vector.
        Step-3. Now using that prevDist vector try to update the originalDist vector(This will ensure that only ith level distances are updated at ith iteration if it is possible and it is minimum)
        Step-4. Finally return the ith Dist vector
        Testcase: 9, [[0,1,1],[1,2,1],[2,3,1],[3,7,1],[0,4,3],[4,5,3],[5,7,3],[0,6,5],[6,7,100],[7,8,1]], 0, 8, 3
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