class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(m, 0));
        vector<vector<char>> path(n, vector<char>(m, ' '));
        
        dp[(n-1)%2][m-1] = grid[n-1][m-1];
        
        for(int j=m-2; j>=0; j--){
            dp[(n-1)%2][j] = dp[(n-1)%2][j+1]+grid[n-1][j];
            path[n-1][j] = 'R';
        }
        
        for(int i = n-2; i>=0; i--){
            dp[i%2][m-1] = dp[(i+1)%2][m-1]+grid[i][m-1];
            path[i][m-1] = 'D';
            for(int j = m-2; j>=0; j--){
                if(dp[(i+1)%2][j] < dp[i%2][j+1]){
                    dp[i%2][j] = dp[(i+1)%2][j]+grid[i][j];
                    path[i][j] = 'D';
                }else{
                    dp[i%2][j] = dp[i%2][j+1]+grid[i][j];
                    path[i][j] = 'R';
                }
            }
        }
        
        int i = 0, j = 0;
        while(i!=n-1 || j!= m-1){
            cout << path[i][j];
            if(path[i][j] == 'R') j++;
            else i++;
        }
        
        return dp[0][0];
        
        
        
        
    }
    //T - O(m*n)
    //S - O(2n) for minPath sum and O(m*n) for actual path;
};