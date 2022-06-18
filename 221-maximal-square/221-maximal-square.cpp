class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> dp(m, 0);
        
        int maxArea = 0;
            
        for(int j=0; j<m; j++){
            dp[j] = matrix[0][j]-'0';
            maxArea = max(maxArea, dp[j]*dp[j]);
        }
        
        for(int i=1; i<n; i++){
            int dpI_1AndJ_1 = dp[0];
            dp[0] = matrix[i][0]-'0';
            maxArea = max(maxArea, dp[0]*dp[0]);
            
            for(int j=1; j<m; j++){
                
                
                int dpI_1AndJ = dp[j];
                if(matrix[i][j] != '0')
                    dp[j] = min(dpI_1AndJ, min(dp[j-1], dpI_1AndJ_1))+1;
                else
                    dp[j] = 0;
                dpI_1AndJ_1 = dpI_1AndJ;
                maxArea = max(maxArea, dp[j]*dp[j]);
            }
        }
           
        return maxArea;
    }
    //T - O(n*m)
    //S - O(n*m)  (can be reduced to O(1m))
};