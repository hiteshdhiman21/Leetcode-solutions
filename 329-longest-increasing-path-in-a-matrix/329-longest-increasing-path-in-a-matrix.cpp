class Solution {
public:
    
    
    
    int dfs(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp, int n, int m, int lastVal){
        
        if(i==-1 || i==n || j==-1 || j==m || matrix[i][j] <= lastVal) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        vector<int> dx({-1, +1, 0, 0});
        vector<int> dy({0, 0, -1, +1});
        int ans = 0;
        for(int d = 0; d < 4; d++){
            int ni = i+dx[d], nj = j+dy[d];
            ans = max(ans, 1+dfs(matrix, ni, nj, dp, n, m, matrix[i][j]));
        }
        
        return dp[i][j]=ans;       
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       
        //This problem has an optimal substructure and There are overlapping calls on the same coordinates
        //So, we use dp and then total call on any coordinate points will max be 1.
        //Step-1. We try to calculate ans using dfs on every possible coordinate and therefore try to go to max depth.
        //Step-2. On each coordinate, if the ans is not calculated before we go to its neighbours and calculate the maximum ans and store in dp and return. Otherwise, we just return the ans.
        //Step-3. So, any neighbours will be visited at most once. Now return the max ans out of all starting coordinates.
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int ans = 0;
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans = max(ans, dfs(matrix, i, j, dp, n, m, -1));
            }
        }
        
       return ans;
    }
    //T - O(n*m)
    //S - O(n*m)
};