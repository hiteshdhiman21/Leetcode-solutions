class Solution {
public:
    
   
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        
        queue<pair<int, int>> q;
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i, j));
                    time[i][j] = 0;
                }else if(grid[i][j] == 0){
                    time[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int> pr = q.front(); q.pop();
            int x = pr.first, y = pr.second;
            
            vector<int> dx({0, 0, -1, +1});
            vector<int> dy({-1, +1, 0, 0});
            for(int  d= 0; d<4; d++){
                int nx = x+dx[d], ny = y+dy[d];
                if(nx == -1 || ny == -1 || nx == n || ny==m || time[nx][ny]<=time[x][y]) continue;
                
                time[nx][ny] = time[x][y]+1;
                q.push(make_pair(nx, ny));
            }
            
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, time[i][j]);
            }
        }
        
        if(ans == INT_MAX)
        return -1;
        return ans;
    }
};