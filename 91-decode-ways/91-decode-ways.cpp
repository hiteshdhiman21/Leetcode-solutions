class Solution {
public:
        
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        
        dp[n] = 1;
        for(int ind = n-1; ind >= 0; ind--){
            if(s[ind]=='0')
                dp[ind] = 0;
            else{
                dp[ind] += dp[ind+1];
                if(ind+1 < s.size() && (s[ind]-'0')*10 + (s[ind+1]-'0') <= 26)
                    dp[ind] += dp[ind+2];
            }
        }
        
        return dp[0];        
    }
    //T - O(n)
    //S - O(n)
};