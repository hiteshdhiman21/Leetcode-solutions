#include <vector>

class Solution {
public:
  /*  int longestCommonSubsequence(string text1, string text2, vector<vector<int>> dp) {
        if(text1.size() == 0 || text2.size() == 0)
            return 0;
        
        int m= text1.size();
        int n= text2.size();
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        int ans=0;
        if(text1[0] == text2[0]){
            ans = 1+longestCommonSubsequence(text1.substr(1), text2.substr(1), dp);
        }
        
        int ans1 = longestCommonSubsequence(text1.substr(1), text2, dp);
        int ans2 = longestCommonSubsequence(text1, text2.substr(1), dp);
        ans = max(ans, max(ans1, ans2));
        dp[m][n] = ans;
        return dp[m][n];
    }
    
    int longestCommonSubsequence(string text1, string text2){
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return longestCommonSubsequence(text1, text2, dp);
    }*/
    
    int longestCommonSubsequence(string text1, string text2){
        int m= text1.size();
        int n= text2.size();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        
        for(int i = m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(text1[i] == text2[j]){
                    dp[i%2][j] = 1+dp[(i+1)%2][j+1];
                }else{
                    dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j+1]);
                }
            }
        }
        
        return dp[0][0];
    }
    //T - O(m*n)
    //S - O(m*n)
};
