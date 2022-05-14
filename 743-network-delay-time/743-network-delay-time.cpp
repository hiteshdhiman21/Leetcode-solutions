#define INF 1e9;

class Solution {
public:
    
    int findMinVertex(int n, vector<int> &time, vector<bool> &visited){
        int minVertex = -1;
        int minTime = INF;
        for(int i=1;i<=n; i++){
            if(visited[i]) continue;
            if(minTime > time[i]){
                minVertex = i;
                minTime = time[i];
            }
        }
        return minVertex;
    }
    
    void dijk(vector<vector<int>>& gtimes, int n, int k, vector<int> &time, vector<bool>& visited){
        
        time[k] = 0;
        
      
        
        for(int i=1; i<=n-1; i++){
            int minVertex = findMinVertex(n, time, visited);
            if(minVertex == -1) break;
            visited[minVertex] = true;
            
            //cout << endl << i << endl;
            
            for(int j=1; j<=n; j++){
               // cout << j << ": ";
                if(visited[j] || gtimes[minVertex][j] == -1) continue;
                //cout << j << ": ";
                time[j] =min(time[j], time[minVertex]+gtimes[minVertex][j]);
            }   
        }
        
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n+1, 1e9);
        vector<bool> visited(n+1, false);
        
        vector<vector<int>> gtimes(n+1, vector<int>(n+1, -1));
        for(int i=0; i<times.size(); i++){
            int f = times[i][0], s= times[i][1], t = times[i][2];
            gtimes[f][s] = t;
        }
        
        dijk(gtimes, n, k, time, visited);
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = max(ans, time[i]);
            if(time[i] == 1e9){
                ans = -1;
                break;
            }
        }
        
        return ans;
    }
};