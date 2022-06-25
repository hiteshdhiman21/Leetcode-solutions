class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int err = 0;
        int n = nums.size();
        for(int i = 0; i+1 < n; i++){
            
            if(nums[i] > nums[i+1]){
                if(err++ || i-1 >= 0 && i+2 < n && nums[i-1] > nums[i+1] && nums[i+2] < nums[i])
                    return false;                
            }
        }
        
        return true;
    }
};