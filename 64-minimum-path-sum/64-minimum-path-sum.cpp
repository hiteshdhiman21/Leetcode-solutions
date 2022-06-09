class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(m, 0));
        
        dp[(n-1)%2][m-1] = grid[n-1][m-1];
        
        for(int j=m-2; j>=0; j--){
            dp[(n-1)%2][j] = dp[(n-1)%2][j+1]+grid[n-1][j];
        }
        
        for(int i = n-2; i>=0; i--){
            dp[i%2][m-1] = dp[(i+1)%2][m-1]+grid[i][m-1];
            for(int j = m-2; j>=0; j--){
                dp[i%2][j] = min(dp[(i+1)%2][j], dp[i%2][j+1]) + grid[i][j];
            }
        }
        
        return dp[0][0];
    }
};