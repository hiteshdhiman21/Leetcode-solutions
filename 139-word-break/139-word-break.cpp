class Solution {
public:
    
    bool isMatched(string& s, int& si, string &w){
        for(int i = 0; i< w.size(); i++){
            if(i+si == s.size() || s[i+si] != w[i]) return false;
        }
        return true;        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<bool> dp(n+1);
        dp[n] = true;
        
        for(int i=n-1; i>=0; i--){
            for(string &w: wordDict){
                
                if(isMatched(s, i, w)){
                    dp[i] = dp[i+w.size()];
                }
                
                if(dp[i] == true) break;
            }
        }
        
        return dp[0];
    }
    //T - O()
    //S - O()
    
};