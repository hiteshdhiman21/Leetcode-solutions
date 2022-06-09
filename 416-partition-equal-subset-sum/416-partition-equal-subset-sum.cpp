class Solution {
public:
    /*
    bool canFindSum(vector<int>& nums, int ind, int req, vector<vector<int>>& dp){
        if(ind == nums.size()){
            return req==0;
        }
        
        if(dp[ind][req] != -1) return dp[ind][req];
        
        bool res = canFindSum(nums, ind+1, req, dp);
        if(req >= nums[ind]) res = res|canFindSum(nums, ind+1, req-nums[ind], dp);
        
        return dp[ind][req] = res;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x:nums) sum+= x;
        
        if(sum%2 == 1) return false;
        
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()*100+1, -1));
        
        return canFindSum(nums, 0, sum/2, dp);
    }
    //T - O(n*TotalSum)
    //S - O(n*TotalSum)*/
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x:nums) sum+= x;
        
        if(sum%2 == 1) return false;
        
        int req = sum/2;
        
        vector<bool> isPos(req+1);
        isPos[0] = true;
        
        for(int x:nums){
            for(sum = req-x; sum >= 0; sum--){
                isPos[sum+x] = isPos[sum+x] || isPos[sum];
            }
        }
        
        return isPos[req];
    }
    //T - O(n*TotalSum)
    //S - O(TotalSum)
};