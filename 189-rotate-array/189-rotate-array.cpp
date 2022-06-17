class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      /*Step-1. Reverse the whole array. Last k elements now will be in first k positions and first n-k will now be at the last n-k positions (both in reverse order).
        Step-2. Now just reverse the first k and last n-k elements separately and we will get the required array*/
      
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
    //T - O(2n)
    //S - O(1)
};