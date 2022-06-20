class Solution {
public:
    
    using MinHeap = priority_queue< tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int,int,int>> >; 
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      /*Approach: Dijkstra algo with some modifications
        In addition to {dist, node} also use {dist, node, stops}
        Use stops and dist array for setting a benchMark. dist[x] stores the minimum dist till now to reach x from source and stops[x] stores the no. of stops to reach x via minPath. 
        i.e. If a new path comes with dist > preDist and stops > preStops. Then no need to choose this path.
        Else if a new path comes with dist < preDist (stops not matter). Then this path can be potential ans. hence push it in the queue and update dist[x] and stops[x] for this path. i.e, set benchmarks according to minDist.
        Else if a new path comes with dist > preMinDist but stops < preStops. Then this path can be potential ans. hence putsh it in the queue and update dist[x] and stops[x] for this path. i.e, set benchmarks according to minStops.*/
        
        
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
                                                                   
            if(cur == dst) return curDist;
            if(curStops == k+1) continue;
            for(auto& [x, curToxDist]: adj[cur]){
                int nextDist = curDist + curToxDist;
                int nextStops = curStops+1;
                
                if(nextDist < dist[x]){
                    dist[x] = nextDist;  //Setting benchmark according to minDist
                    stops[x] = nextStops; 
                    pq.push({nextDist, x, nextStops});
                }else if(nextStops < stops[x]){
                    dist[x] = nextDist;  //Setting benchmark according to minStops
                    stops[x] = nextStops; 
                    pq.push({nextDist, x, nextStops});
                }
            }
            
        }
        
        return -1;        
    }
};