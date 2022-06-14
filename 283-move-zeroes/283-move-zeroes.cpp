class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ind = -1;
        for(int i =0; i< nums.size(); i++){
            
           if(nums[i] !=0){
               nums[++ind] = nums[i];
           }            
        }
        
        for(int i=ind+1; i<nums.size(); i++) nums[i] = 0;
    }
    //T - O(n)
    //S - O(1)
};