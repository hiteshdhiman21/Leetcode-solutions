class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Dutch-National flag algorithm
        int n = nums.size();
        
        int low = 0; //0
        int mid = 0; //1
        int high = n-1; //2
        
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid++], nums[low++]);
            }else if(nums[mid] == 2){
                swap(nums[mid], nums[high--]);
            }else{
                mid++;
            }
        }
    }
    //Low  mid high
    // 0 0 0l 1M 2 0 0 1
};