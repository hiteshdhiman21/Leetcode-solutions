class Solution {
public:
    
    bool bipartiteBFS(int st, vector<vector<int>>& graph, vector<int> &color){
        //Step-1. Color the first vertex as 0.
        //Step-2. For every node, color all of its uncolored negihbours with oppsoite colors.
        //Step-3. If any neighbour is colored with the same color as the current node. Return false.
        //Steo-4. At last return true.
        
        queue<int> q;
        q.push(st);
        color[st] = 0;
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            int curPart = color[cur];
            
            for(int x:graph[cur]){
                if(color[x] == -1){
                    q.push(x);
                    color[x] = 1-curPart; //For 1, it is 0 and for 0, it is 1
                }else if(color[x] != 1-curPart){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        //Approach: It is just the same as dividing the graph into 2 parts or 2-coloring problem.
        //If i am able to divide the graph into two parts or color it using 2 color then return true. Else return false.
        //Step. Call isBipartite for all components and if any return false, return false. Else return true.
        
        
        int n = graph.size();
        
        vector<int> color(n, -1);
        
        for(int i =0; i<n; i++){ 
            if(color[i] == -1 && !bipartiteBFS(i, graph, color)) return false;
        }
        
        return true;
    }
    //T - O(V+E)
    //S - O(V)
};