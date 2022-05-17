class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-2;
        int ind = -1;
        
        //start denotes that all the elements before the start only contain duplicates.
        //After start it can contain duplicates as well as single element.
        //After the end+1, it only contains duplicate element.
        while(start <= end){
            int mid = (start+end)/2;
            
            if(nums[mid] == nums[mid^1]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return nums[start];
    }
    //T - log(n)
    //S - O(1)
};