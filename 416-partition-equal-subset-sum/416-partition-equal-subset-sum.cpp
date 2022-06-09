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
        //Using only 1-D array, trick learnt in CodeForces time.
        /*Taking or Not-taking both are considered. Not taking as we are not resetting old values. Taking as if for nums[ind] = x, some sum-x is already possible, then sum is also possibly by taking x.*/
        
        int sum = 0;
        for(int x:nums) sum+= x;
        
        if(sum%2 == 1) return false;
        
        int req = sum/2;
        
        vector<bool> isPos(req+1);
        isPos[0] = true;
        
        for(int x:nums){
            for(sum = req; sum >= 0; sum--){
                if(sum-x >= 0)
                isPos[sum] = isPos[sum] || isPos[sum-x];
            }
        }
        
        return isPos[req];
    }
    //T - O(n*TotalSum)
    //S - O(TotalSum)
};