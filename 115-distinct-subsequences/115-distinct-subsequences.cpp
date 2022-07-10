class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        vector<vector<long>> dp(n1+1, vector<long>(n2+1, 0));
        dp[n1][n2] = 1;
        
        for(int i = n1; i>=0; i--){
            for(int j=n2; j>=0; j--){
                
                if(i<n1 && j<n2 && s[i] == t[j])
                    dp[i][j] = dp[i+1][j+1];
                
                if(i<n1)
                dp[i][j] += dp[i+1][j];
                dp[i][j] = min(dp[i][j], (long)INT_MAX);
            }
        }
        
        return dp[0][0];
    }
    //T - O(n1*n2)
    //S - O(n1*n2)
};