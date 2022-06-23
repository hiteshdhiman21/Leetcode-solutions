class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        
        vector<string> dp(2);
        
        dp[1] = "1";
        for(int i=2; i<=n; i++){
            dp[i%2] = "";
            int cnt = 0;
            int j;
            for(j=0; j<dp[(i-1)%2].size(); j++){
                if(j==0 || dp[(i-1)%2][j] == dp[(i-1)%2][j-1])
                    cnt++;
                else{
                    dp[i%2] += to_string(cnt) + dp[(i-1)%2][j-1];
                    cnt = 1;
                }
            }
            
            dp[i%2] += to_string(cnt)+dp[(i-1)%2][j-1];
        }
        
        return dp[n%2];
    }
    //T - O(n*k) , where k = avg length of n strings
    //S - O(2*maxLength)
};