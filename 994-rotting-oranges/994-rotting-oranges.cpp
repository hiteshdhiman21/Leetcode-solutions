class Solution {
public:
    
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& time, int i, int j, int timecnt){
        //cout << i << " " << j << endl;
        if(i == -1 || j==-1 || i==grid.size() || j==grid[0].size())
            return;
        
        if(grid[i][j] == 0 || time[i][j] <= timecnt) return;
        time[i][j] = timecnt;
        
        vector<int> dx({0, 0, -1, +1});
        vector<int> dy({-1, +1, 0, 0});
        
        for(int d=0; d<4; d++){
            bfs(grid, time, i+dx[d], j+dy[d], timecnt+1);
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //cout <<i << " " << j << endl;
                if(grid[i][j] == 2 && time[i][j] != 0){
                    bfs(grid, time, i, j, 0);
                }else if(grid[i][j] == 0){
                    time[i][j] = 0;
                }
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
        else
        return ans;
    }
};