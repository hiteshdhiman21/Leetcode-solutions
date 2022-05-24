class Solution {
public:
    int solve(vector<int>& nums, int ind, int target, vector<vector<int>> &dp){
        if(ind == nums.size()){
            if(target == 1000) return 1;
            else return 0;
        } 
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int ans = solve(nums, ind+1, target-nums[ind], dp); //If used positive sign
        if(target+nums[ind] <= 2000)
        ans += solve(nums, ind+1, target+nums[ind], dp);   //If used negative sign
        return dp[ind][target] = ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(nums.size(), vector<int>(2005, -1));
        return solve(nums, 0, target+1000, dp);
    }
};