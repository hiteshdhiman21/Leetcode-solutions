class Solution {
public:
    
    
    
    
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size() != s3.size()) return false;
        vector<bool> dp(s2.size()+1);
        
        int n1 = s1.size(), n2 = s2.size();
        dp[n2] = true;
        
        for(int i=n1; i>=0; i--){
            for(int j=n2; j>=0; j--){
                bool oldVal = dp[j];
                dp[j] = false;
                
                if(i==n1 && j==n2)
                    dp[j] = true;
                
                if(i<n1 && s1[i] == s3[i+j])
                    dp[j] = oldVal;
                if(j<n2 && s2[j] == s3[i+j])
                    dp[j] = dp[j] | dp[j+1];
                
            }
        }
        
        return dp[0];
    }
};