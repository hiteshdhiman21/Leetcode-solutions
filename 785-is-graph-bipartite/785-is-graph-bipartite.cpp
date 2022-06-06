class Solution {
public:
    
    bool bipartiteDFS(int st, vector<vector<int>>& graph, vector<int> &color, int myColor){
        //Step-1. Color the current vertex as given color.
        //Step-2. Color all of its uncolored negihbours with oppsoite colors.
        //Step-3. If any neighbour is colored with the same color as the current node. Return false.
        //Steo-4. At last return true.
        
        color[st] = myColor;
        
        for(int x: graph[st]){
            if(color[x] == -1 && !bipartiteDFS(x, graph, color, 1-myColor)) return false;
            else if(color[x] != 1-myColor) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        //Approach: It is just the same as dividing the graph into 2 parts or 2-coloring problem.
        //If i am able to divide the graph into two parts or color it using 2 color then return true. Else return false.
        //Step. Call bipartiteDFS for all components and if any return false, return false. Else return true.
        
        
        int n = graph.size();
        
        vector<int> color(n, -1);
        
        for(int i =0; i<n; i++){ 
            if(color[i] == -1 && !bipartiteDFS(i, graph, color, 0)) return false;
        }
        
        return true;
    }
    //T - O(V+E)
    //S - O(V)
};