class Solution {
public:
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int n, int m){
        queue<pair<int,int>> q;
        
        if(vis[0][0] == true){
            for(int i = 0; i<n; i++) q.push({i, 0});
            for(int j = 0; j < m; j++) q.push({0, j});
        }else{
            for(int i = 0; i<n; i++) q.push({i, m-1});
            for(int j = 0; j < m; j++) q.push({n-1, j});
        }
        
        vector<int> dx({-1, 1, 0, 0});
        vector<int> dy({0, 0, -1, 1});
        
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            
            for(int d = 0; d<4; d++){
                int nx = x+dx[d], ny = y+dy[d];
                if(nx == -1 || nx == n || ny == -1 || ny == m || vis[nx][ny] || heights[nx][ny] < heights[x][y]) continue;
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        
        vector<vector<bool>> pacific(n, vector<bool> (m, false));
        vector<vector<bool>> atlantic(n, vector<bool> (m, false));
        
        for(int i = 0; i < n; i++){
            pacific[i][0] = atlantic[i][m-1] = true;
        }
        
        for(int j = 0; j < m; j++){
            pacific[0][j] = atlantic[n-1][j] = true;
        }
        
        bfs(heights, pacific, n, m);
        bfs(heights, atlantic, n, m);
        
        vector<vector<int>> res;
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        
        return res;
    }
    //T - O(n*m)
    //S - O(n*m)
};