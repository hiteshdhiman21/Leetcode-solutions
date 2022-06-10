class Solution {
public:
    
    /*bool contains(string s, vector<string>& wordDict){
        for(int i=0; i<wordDict.size(); i++){
            if(s==wordDict[i])
                return true;
        }
        return false;
    }
    
    bool solve(string s, vector<string>& wordDict, vector<int>& dp){
        
        if(s.size() == 0)
            return true;
        
        if(dp[s.size()] != -1)
            return dp[s.size()];
        
        bool ans = false;
        for(int i=0; i<s.size(); i++){
            if(contains(s.substr(0, i+1), wordDict))
            ans = solve(s.substr(i+1, s.size()), wordDict, dp)|| ans;
            
            if(ans){
                dp[s.size()] = (int)ans;
                return dp[s.size()];
            }
        }
        
        dp[s.size()] = (int)ans;
        return dp[s.size()];
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<int> dp(s.size()+1, -1);
        
        return solve(s, wordDict, dp);
        
    }*/
    
    bool isMatched(string& s, int& si, string &w){
        for(int i = 0; i< w.size(); i++){
            if(s[i+si] != w[i]) return false;
        }
        return true;        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<bool> dp(n+1);
        dp[n] = true;
        
        for(int i=n-1; i>=0; i--){
            for(string &w: wordDict){
                if(n-i < w.size()) continue;
                
                if(!isMatched(s, i, w)) continue;
                
                dp[i] = dp[i+w.size()];
                
                if(dp[i] == true) break;
            }
        }
        
        return dp[0];
    }
    //T - O()
    //S - O()
    
};