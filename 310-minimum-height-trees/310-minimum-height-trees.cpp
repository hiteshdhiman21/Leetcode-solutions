class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
         vector<int> inDegree(n);
        for(auto _: edges){
            adj[_[0]].push_back(_[1]);
            adj[_[1]].push_back(_[0]);
            inDegree[_[0]]++;
            inDegree[_[1]]++;
        }
        
        vector<int> res;
        
        int rem = n;
       
        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDegree[i] <= 1)
                q.push(i);
        }
        
        while(rem>2){
            int size = q.size();
            for(int i=0; i<size; i++){
                int cur = q.front(); q.pop();
                rem--;
                for(int x: adj[cur]){
                    inDegree[x]--;
                    if(inDegree[x] == 1){
                        q.push(x);
                    }
                }  
            }
            
        }
        
        while(!q.empty()) res.push_back(q.front()), q.pop();
        
        return res;
    }
};