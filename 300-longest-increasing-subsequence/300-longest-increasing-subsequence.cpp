class Solution {
public:
    
    //Memoization -recursive. Tabulatio - iterative.
    //Tabulation - Bottom to up. In a tabulated version, all the entries must be filled one by one.
    //Memoization - In a memoized version, entries in the table are filled on demand.
    
    /*int solve(vector<int> &nums, int ind, int prevInd, vector<vector<int>>& dp){
        if(ind == nums.size()) return 0;
        
        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
        
        int len = solve(nums, ind+1, prevInd, dp);
        if(prevInd == -1 || nums[prevInd] < nums[ind]) len = max(len, 1+solve(nums, ind+1, ind, dp));
        
        return dp[ind][prevInd+1] = len; 
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        return solve(nums, 0, -1, dp);
    }
    //T - O(n^2)
    //S - O(n^2)
    */
    
    /*int lengthOfLIS(vector<int>& nums) {
        //Tabulation unoptimized
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int ind = n-1; ind >=0; ind--){
            for(int prevInd = ind-1; prevInd >= -1; prevInd--){
                int len = dp[ind+1][prevInd+1]; //Leaving it
                if(prevInd == -1 || nums[prevInd] < nums[ind]) 
                    len = max(len, 1+dp[ind+1][ind+1]); //Taking it
                dp[ind][prevInd+1] = len;
            }
        }
        
        return dp[0][0];
    }
    //T - O(n^2)
    //S - O(n^2)
    */
    
    /*int lengthOfLIS(vector<int>& nums) {
        
        //Space optimized tabulation
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        
        for(int ind = n-1; ind >=0; ind--){
            for(int prevInd = ind-1; prevInd >= -1; prevInd--){
                int len = dp[(ind+1)%2][prevInd+1]; //Leaving it
                if(prevInd == -1 || nums[prevInd] < nums[ind]) 
                    len = max(len, 1+dp[(ind+1)%2][ind+1]); //Taking it
                dp[ind%2][prevInd+1] = len;
            }
        }
        
        return dp[0%2][0];
    }
    //T - O(n^2)
    //S - O(2n)
    */
    
    int lengthOfLIS(vector<int>& nums) {
        
        //Tabulation of best type
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for(int ind =0; ind<n; ind++){
            for(int prevInd = ind-1; prevInd>=0; prevInd--){
                if(nums[prevInd] < nums[ind]) 
                    dp[ind] = max(dp[ind], dp[prevInd]+1);
            }
        }
       
        int maxLen = 0;
        for(auto len: dp)
            maxLen = max(len, maxLen);
        
        return maxLen;
    }
    //T - O(n^2)
    //S - O(n)
};