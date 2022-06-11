class Solution {
public:
    
    bool isMatched(string& s, int& si, string &w){
        for(int i = 0; i< w.size(); i++){
            if(i+si == s.size() || s[i+si] != w[i]) return false;
        }
        return true;        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //Approach: DP
        //Try to match every word in word dict with the string starting from the different indices to get a matched substring.
        
        int n = s.size();  //int m = wordDict.size()
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
    //T - O(n*m*k), where k = avg word length and m = wordDict size
    //S - O(n)
    
};