class Solution {
public:

    
    bool wordBreak(string str, vector<string>& wordDict) {
        //Approach: DP
        //Intuition: Try to find substrings in the wordDictionary starting from the last.
        
        int n = str.size(); //int m = wordDict.size()
        unordered_set<string> wordDictMap(wordDict.begin(), wordDict.end());
        vector<bool> dp(n+1);
        dp[n] = true;
        
        for(int i=n-1; i>=0; i--){
            string cur = "";
            for(int j = i; j<= n; j++){
                cur += str[j];
                if(wordDictMap.count(cur)){
                    dp[i] = dp[i+cur.size()];
                    if(dp[i] == true) break;
                }
            }
        }
        
        return dp[0];
    }
    //T - O(n^3) 
    //S - O(m*k)+O(n) , where k = avg w length
    
    
};