class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        //Just use DP
        //if(grid[i][j] == 0), dp[i][j] = dp[i+1][j]+dp[i][j+1]
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        
        dp[n-1][m-1] = (grid[n-1][m-1] == 0)?1:0;
        for(int i=n-2; i>=0; i--){
            if(grid[i][m-1] == 0)
            dp[i][m-1] = dp[i+1][m-1];
        }
        
        for(int j=m-2; j>=0; j--){
            if(grid[n-1][j] == 0)
            dp[n-1][j] = dp[n-1][j+1]; 
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                if(grid[i][j] == 0)
                    dp[i][j] = dp[i+1][j]+dp[i][j+1];
                //Otherwise already setted zero
            }
        }
        
        return dp[0][0];
        //T - O(m*n)
        //S - O(m*n)
    }
};