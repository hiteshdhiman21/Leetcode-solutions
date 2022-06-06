class Solution {
public:
    
    bool bipartiteBFS(int st, vector<vector<int>>& graph, vector<int> &part){
        queue<int> q;
        q.push(st);
        part[st] = 1;
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            int curPart = part[cur];
            
            for(int x:graph[cur]){
                if(part[x] == 0){
                    q.push(x);
                    part[x] = 3-curPart; //For 1, it is 2 and for 2, it is 3
                }else if(part[x] != 3-curPart){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> part(n, 0);
        
        for(int i =0; i<n; i++){
            if(!part[i] && !bipartiteBFS(i, graph, part)) return false;
        }
        
        return true;
    }
};