class Solution {
public:
    
    vector<vector<int>> dp;
    
    bool solve(string &s1, string &s2, string& s3, int i1, int i2){
        if(i1 == s1.size() && i2 == s2.size())
            return true;
        
        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        bool res = false;
        if(i1 < s1.size() && s3[i1+i2] == s1[i1]){
            res = res | solve(s1, s2, s3, i1+1, i2);
        }
        
        if(i2 < s2.size() && s3[i1+i2] == s2[i2]){
            res = res | solve(s1, s2, s3, i1, i2+1);
        }
        
        return dp[i1][i2] = res;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()) return false;
        dp.assign(s1.size()+1, vector<int>(s2.size()+1, -1));
        
        return solve(s1, s2, s3, 0, 0);
    }
};