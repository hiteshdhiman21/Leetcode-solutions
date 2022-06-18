class Solution {
public:
    bool canJump(vector<int>& nums) {
      /*Intution: DP and 1 greedy observation  
        Greedy: If we can reach j from i. Then it is optimal for lower indices to come to j via i. Because it may be possible that for lower indices the jump is not much high so that it is impossible till j but possible till i. Because if some k can jump till j, then it can also jump till k, k+1, .... j-1, j
        Therefore we will traverse from back and use this fact to find i for every j.  i.e, if we can jump from i to some j. Then for lower indices we will ask to jump till i only.
        */ 
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