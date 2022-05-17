class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ind = nums.size()-1;
        
        int start = 1;
        int end = nums.size()-1;
        
        while(start <= end){
            int mid = (start+end)/2;
         
            if(mid%2==1){
                if(nums[mid] != nums[mid-1]){
                    ind = mid-1;
                    end= mid-1;
                }else{
                    start = mid+1;
                }
            }else{
                if(mid == 0 || nums[mid] == nums[mid-1]){
                    ind = mid-1;
                    end= mid-1;
                }else{
                    start = mid+1;
                }
            }
            
        }
        
        return nums[ind];
    }
};