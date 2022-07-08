class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        if(nums.size() <= 4) return 0;
        
        sort(nums.begin(), nums.end());
        int res = nums.back() - nums[0];
        for(int i = 0; i<=3; i++){
            res = min(res, nums[nums.size()-1-3+i] - nums[i]);
        }
        
        return res;
    }
    //T - nlogn
    //S - O(1)
};