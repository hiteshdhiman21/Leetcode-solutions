class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        int maxArea = 0;
        
        for(int i=0; i<n; i++){
            dp[i][0] = matrix[i][0]-'0';
            maxArea = max(maxArea, dp[i][0]);
        }
            
        for(int j=1; j<m; j++){
            dp[0][j] = matrix[0][j]-'0';
            maxArea = max(maxArea, dp[0][j]);
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == '0') continue;
                
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
                maxArea = max(maxArea, dp[i][j]*dp[i][j]);
            }
        }
           
        return maxArea;
    }
    //T - O(n*m)
    //S - O(n*m)  (can be reduced to O(1m))
};