class Solution {
public:

    //Just used BFS. Didn't even maintained a visited array. 
    //Pushing everything into the queue, but running the loop only for elements inserted in the last iteration and popping them.
    //If this iteration insert any element, means queue is not empty after this iteration. Then it means to rot these oranges, it would take one more day. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int tot = 0;
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) q.push(make_pair(i, j));
            }
        }
        
        int cntRotten = 0;
        int days = 0;
        
        vector<int> dx({-1, 1, 0, 0});
        vector<int> dy({0, 0, -1, 1});
        
        while(!q.empty()){
            int k = q.size();
            cntRotten+=k;
            
            while(k--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int d = 0; d<4; d++){
                    int nx = x+dx[d], ny = y+dy[d];
                    if(nx == -1 || nx == n|| ny == -1 || ny == m || grid[nx][ny] != 1) continue;
                    
                    q.push(make_pair(nx, ny));
                    grid[nx][ny] = 2;
                }
            }
            
            if(!q.empty()) days++;
            
        }
        
        return cntRotten==tot?days:-1;
        
        
    }
};