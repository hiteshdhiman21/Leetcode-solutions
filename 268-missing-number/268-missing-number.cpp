class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xr_1tilln = 0;
        int xr_nums = 0;
        
        for(int i=0; i<n; i++){
            xr_1tilln = xr_1tilln ^ (i+1);
            xr_nums = xr_nums^(nums[i]);
        }
        
        return xr_nums^xr_1tilln; 
        //Can be done with only 1 xr variable
        
    }
    //T - O(n)
    //S - O(1)
};