class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpTo = nums.size()-1;
        for(int jumpFrom = nums.size()-2; jumpFrom >= 0; jumpFrom--){
            if(jumpFrom+nums[jumpFrom] >= jumpTo)
                jumpTo = jumpFrom;
        }
        
        return jumpTo == 0;
    }
    //T - O(n)
    //S - O(1)
};