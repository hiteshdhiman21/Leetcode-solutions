class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid] < nums[r]){ //Pivot can only be in [left, mid]
                r = mid;
            }else{ //Pivot can only be in [mid+1, end]
                l = mid+1;
            }
        }
        
        return nums[r];
    }
    //T - O(n)
    //S - O(1)
};