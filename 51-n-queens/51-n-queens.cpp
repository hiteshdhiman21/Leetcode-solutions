class Solution {
public:
    
    void solve(vector<string> &board, int n, int i, vector<vector<string>>& ans, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2){
        
        if( i== n){
            ans.push_back(board);
            return;
        }
        
        for(int j =0; j<n; j++){
            if(col[j] || diag1[i+j] || diag2[j-i+n-1]) continue;
            
            board[i][j] = 'Q';
            col[j] = diag1[i+j] = diag2[j-i+n-1] = true;
            
            solve(board, n, i+1, ans, col, diag1, diag2);
            
            board[i][j] = '.';
            col[j] = diag1[i+j] = diag2[j-i+n-1] = false;
        }
        
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        for(int i=0; i<n; i++){
            for(int j =0; j<n; j++) board[i].push_back('.');
        }
        
        vector<bool> col(n);
        vector<bool> diag1(2*n-1);
        vector<bool> diag2(2*n-1);
        
        vector<vector<string>> ans;
        
        solve(board, n, 0, ans, col, diag1, diag2);
        return ans;
    }
};