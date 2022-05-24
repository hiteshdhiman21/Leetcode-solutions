class Solution {
public:
    int solve(vector<int>& nums, int ind, int target, vector<vector<int>> &dp){
        if(ind == nums.size()){
            //It means target is 0
            if(target == 1000) return 1;
            else return 0;
        } 
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        //If used positive sign before nums[ind]
        int ans = solve(nums, ind+1, target-nums[ind], dp); 
        
        //If used negative sign before nums[ind]
        if(target+nums[ind] <= 2000)  //else greater than 2000(real : 1000) target is not possible according to constraints        
        ans += solve(nums, ind+1, target+nums[ind], dp);   
        
        return dp[ind][target] = ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        //Just shift the origin from 0 to 1000. 
        //-1000 -> 0
        // 0 -> 1000
        //1000 -> 2000
        int n = nums.size();
        vector<vector<int>> dp(nums.size(), vector<int>(2005, -1));
        return solve(nums, 0, target+1000, dp);
    }
};