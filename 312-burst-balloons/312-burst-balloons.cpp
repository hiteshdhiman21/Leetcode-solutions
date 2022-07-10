class Solution {
public:
    
    int solve(vector<int> &nums, int s, int e, vector<vector<int>> &dp){
        if(s>e) return 0;
        if(dp[s][e] != -1)
            return dp[s][e];
        
        int res = 0;
        for(int b = s; b<=e; b++){
            int score = nums[b];
            if(s!=0) score *= nums[s-1];
            if(e!=nums.size()-1) score *= nums[e+1];
            
            score += solve(nums, s, b-1, dp)+ solve(nums,b+1, e, dp);
            res = max(res, score);
        }
        
        return dp[s][e] = res;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(nums, 0, nums.size()-1, dp);
    }
    //T - O(n*n)
    //S - O(n*n)
};