class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(32, 0);
        
        for(int x: nums){
            for(int b=0; b<32; b++){
                if(x&(1<<b))
                    dp[b]++;
            }
        }
        
        int res = 0;
        for(int b=0; b<32; b++){
            res += (n-dp[b])*dp[b];
        }
        
        return res;
    }
    //T - O(n)
    //S - O(1)
};