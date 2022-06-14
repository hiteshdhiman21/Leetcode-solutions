class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
      /*Step-1. Maintain ind such that all the elements placed till ind are already non-zeros.
        Step-2. Iterating over the array and if nums[i] == 0, skip it
        Step-3. Else nums[++ind] = nums[i].*/
        
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