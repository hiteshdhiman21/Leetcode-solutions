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
/*Best solution for LIS using Binary search (But we can't derive the sequence)
Here lis will not store the original sequence. 
Every itertation we will do lis[ind] = x to make lis elements value small and increasing so that in future it can convert into a new sequence of same size with smaller values and it might give a chance to increase length of the sequence by inserting some small element(>current last && <= previous last) at last. 

case : 4 7 5 6 1 3 4 7
       4, 4 7, 4 5, 4 5 6, 1 5 6, 1 3 6, 1 3 4, 1 3 4 7
    */
        vector<int> lis;
        for(int x:nums){
            if(lis.size() == 0 || lis.back() < x)
                lis.push_back(x);
            else{
                int ind = lower_bound(lis.begin(), lis.end(), x)-lis.begin();
                lis[ind] = x;
            }
        }
        
       return lis.size();
    }
    //T - O(nlogn)
    //S - O(n)
};