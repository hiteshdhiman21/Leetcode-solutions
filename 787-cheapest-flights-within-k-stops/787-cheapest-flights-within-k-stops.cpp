class Solution {
public:
    
    using MinHeap = priority_queue< tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int,int,int>> >; 
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < flights.size(); i++)
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        
        vector<int> dist(n, INT_MAX);
        vector<int> stops(n, INT_MAX);
        
        dist[src] = 0;
        stops[src] = 0;
        
        MinHeap pq;
        pq.push({0, src, 0});
        
        while(!pq.empty()){
            auto [curDist, cur, curStops] = pq.top(); pq.pop();
            
            cout << endl << curDist << " " << cur << endl;            
            if(cur == dst) return curDist;
            if(curStops == k+1) continue;
            for(auto& [x, curToxDist]: adj[cur]){
                cout << x <<" ";
                int nextDist = curDist + curToxDist;
                int nextStops = curStops+1;
                
                if(nextDist < dist[x]){
                    dist[x] = nextDist;
                    stops[x] = nextStops;
                    pq.push({nextDist, x, nextStops});
                }else if(nextStops < stops[x]){
                    pq.push({nextDist, x, nextStops});
                }
            }
            
        }
        
        return dist[dst] == INT_MAX?-1:dist[dst];        
    }
};