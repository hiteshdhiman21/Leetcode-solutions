class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      /*Two-pointers solution: Using 2 pointers and constructing ans array from the back in decreasing order*/
        
        int n = nums.size();
        
        vector<int> ans(n);
        int i = 0, j = n-1;
        
        int k = n;//Position(Index) till which it is inserted from back
        
        while(i<=j){
            if(nums[i]*nums[i] <= nums[j]*nums[j]){
                ans[--k] = nums[j]*nums[j];
                j--;
            }else{
                ans[--k] = nums[i]*nums[i];
                i++;
            }
        }
        
        return ans;
    }
    //T - O(n)
    //S - O(n) But not auxilarry
};