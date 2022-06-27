class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
      /*Used BFS starting from Boundary O's
        No need for visited array. if Board[i][j] == 'X', No need to change hence continue. Else if board[i][j] == 'S', Already changed and explored hence continue. Else if Board[i][j] == 'O', Not explored but need to explore, Hence set board[i][j] = 'S' and push it into the queue*/
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = 'S';
            }
                
            if(board[i][m-1] == 'O'){
                q.push({i, m-1});
                board[i][m-1] = 'S';
            }
        }
        
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O'){
                q.push({0, j});
                board[0][j] = 'S';
            }
                
            if(board[n-1][j] == 'O'){
                q.push({n-1, j});
                board[n-1][j] = 'S';
            }
        }
        
        vector<int> dx({-1, 1, 0, 0});
        vector<int> dy({0, 0, -1, 1});
        
        
        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            
            for(int d =0; d<4; d++){
                int nx = x+dx[d], ny = y+dy[d];
                if(nx == -1 || nx == n|| ny == -1 || ny == m || board[nx][ny] != 'O')
                    continue;
                
                board[nx][ny] = 'S';
                q.push({nx, ny});
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(board[i][j] == 'S') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
    
    //T - O(n*m)
    //S - O(n*m)
};