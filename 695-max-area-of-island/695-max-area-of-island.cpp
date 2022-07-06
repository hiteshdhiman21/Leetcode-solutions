class Solution {
public:
    vector<int> di = {-1, 1, 0, 0};
    vector<int> dj = {0, 0, -1, 1};
    
    int bfs(vector<vector<int>> &grid, int i, int j){
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        
        int curArea = 0;
        q.push({i, j});
        
        grid[i][j] = 0;
        
        while(!q.empty()){
            auto[ci, cj] = q.front(); q.pop();
            curArea++;
            
            for(int d=0; d<4; d++){
                int ni = ci+di[d];
                int nj = cj+dj[d];
                if(ni==-1 || nj==-1 || ni==n || nj==m || grid[ni][nj] == 0)
                    continue;
                
                grid[ni][nj] = 0;
                q.push({ni, nj});
            }
        }
        
        return curArea;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] != 0)
                    maxArea = max(maxArea, bfs(grid, i, j));
            }
        }
        
        return maxArea;
    }
    //T - O(n*m)
    //S - O(n*m)
};