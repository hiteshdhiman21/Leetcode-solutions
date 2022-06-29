class Solution {
public:
    
    bool isConnected(vector<int>& busA, vector<int> &busB){
        int indA = 0, indB = 0;
        while(indA < busA.size() && indB < busB.size()){
            if(busA[indA] < busB[indB])
                indA++;
            else if(busA[indA] > busB[indB])
                indB++;
            else
                return true;
        }
        
        return false;
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
      /*Approach: BFS on Buses and not Stops
        *Apply BFS on buses, taking each bus as a separate node. Two buses are connected(i.e, we can go from one bus to another), if they               share atleast one common stop.
        *There can be many sourceBuses, which have a stop as source stop.
        *Similarly there can be many destinationBuses, which have a stop as destination stop.
        Step-1. Find all the edges between the buses. Also find all the source and TargetBuses
        Step-2. If source == target, no need to take bus. Hence return 0.
        Step-3. Else Apply BFS and since we will have to take the sourceBus to reach the destinationBus set dist[sourceBus] =1.
        Step-4. Do continue until the q become empty or we find a destinationBus. If found the destinationBus return dist[destinationBus].
        Step-5. Finally if it is not possible to reach the target bus, then it is also not possible to reach the target stop. 
                Hence return -1
                */
        
        
        
        if(source == target) return 0;
         
        int n = routes.size();
        
        unordered_set<int> sourceBuses;
        unordered_set<int> targetBuses;
        
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++){
            if(i == 0) 
                    sort(routes[i].begin(), routes[i].end());
            for(int j = i+1; j<n; j++){
                if(i == 0) 
                    sort(routes[j].begin(), routes[j].end());
                if(isConnected(routes[i], routes[j])){
                    adj[i].push_back(j); 
                    adj[j].push_back(i);
                }                
            }
            
            for(int stop: routes[i]){
                if(stop == source)
                    sourceBuses.insert(i);
                if(stop == target)
                    targetBuses.insert(i);
            }           
        }
        
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        for(int sbus: sourceBuses){
            q.push(sbus);
            dist[sbus] = 1;
        }
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            if(targetBuses.count(cur))
                return dist[cur];
            
            for(int x: adj[cur]){
                if(dist[x] != INT_MAX) continue;
                
                dist[x] = dist[cur]+1;
                q.push(x);
            }
        }
        
        return -1;
    }
    //T - O(n*klogk + n*n*k) , where k = avg length of each routes[i]. nk <= 10^5 according to given constraint no. 4
    //S - O(n^2 + n), n^2 for adj array, n for queue, distArray, unordered_set<int>
};