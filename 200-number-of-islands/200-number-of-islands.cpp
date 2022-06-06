class Solution {
public:
    
    //Can also use DFS
    void bfs(vector<vector<char>>& grid, int sr, int sc){
        vector<int> dx({-1, 1, 0, 0});
        vector<int> dy({0, 0, -1, 1});
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        while(!q.empty()){
            int cr = q.front().first, cc = q.front().second;
            q.pop();
            
            for(int d=0; d<4; d++){
                int nr = cr+dx[d], nc = cc+dy[d];
                if(nr == -1 || nc == -1 || nr == grid.size() || nc == grid[0].size() || grid[nr][nc] == '0')
                    continue;
                
                grid[nr][nc] = '0';
                q.push({nr, nc});
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i =0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1') {
                    bfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    //T - O(m*n)
    //S - O(1) But modified inputted 2d array
};