class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
      /*Toplogical sort
        [v1, v2] == v2->v1, v1 is having dependancy of v2.*/
        
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        
        for(auto& _: prerequisites){
            adj[_[1]].push_back(_[0]);
            inDegree[_[0]]++;
        }
        
        queue<int> q;
        for(int v = 0; v < n; v++){
            if(inDegree[v] == 0)
                q.push(v);
        }
            
        int cnt = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            cnt++;
            
            for(int x: adj[cur]){
                inDegree[x]--;
                if(inDegree[x] == 0)
                    q.push(x);
            }
        }
        
        if(cnt != n) return false;
        else return true;
    }
    //T - O(V+E)
    //S - O(V+E)
};