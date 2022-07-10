class Solution {
public:
    
    int solve(vector<int> &nums, int s, int e, vector<vector<int>> &dp){
        if(s>e) return 0; //No balloon to find last bursted out of all balloons.
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
      /*Intuition: If we try some i to be first stone in [s,e], then subproblems for [s,i-1] and [i+1, e] are inter-related and so we can't call recursion separately for both paritions.
        Instead, We will travel opposite in time and try to find ans. We can think it this way. Stones[s, e] are bursted except one and all the stones before s i.e, [, s-1] and after e i.e, [e+1, ] will be bursted in future. And so it means, currently those [, s-1] and [e+1, ] are present. And out of [s, e], we need to find which will be bursted last and all others have been bursted before(after in reverse time traversing). And so suppose if out of [s, e] we will burst some b now(it means last), it will have its neighbour as (s-1) and (e+1) as they will be bursted after it (before in reverse time traversing) and not in [s,e] as they will be bursted before(after in reverse time traversing). 
        */
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return solve(nums, 0, nums.size()-1, dp);
    }
    //T - O(n*n*n)
    //S - O(n*n)
};