class Solution {
public:
    int rob(vector<int>& nums) {
      /*Dp:
        Two iterations: Since we can't take both nums[0] and nums[nums.size()-1]
        1. Use HouseRobber1 on nums[1...(n-1)]
        2. Use HouseRobber1 on nums[2....n]*/
        if(nums.size() == 1)
            return nums[0];
        
        int n = nums.size();
        vector<int> dp(n);
        
        dp[0] = nums[0]; dp[1] = max(nums[1], nums[0]);
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        
        int res = dp[n-2];
        
        dp[0] = 0; dp[1] = nums[1];
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        
        res = max(res, dp[n-1]);
        
        return res;
    }
    //T - O(n)
    //S - O(n) can be modified to O(1)
};