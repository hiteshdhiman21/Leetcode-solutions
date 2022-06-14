class Solution {
public:
    vector<int> countBits(int n) {
        //DP: dp[i] = dp[i-offSet]. i.e., for every new power of 2 (i.e, 2^x), using 0 to 2^x-1 for calculating 2^x ... 2^(x+1)-1
        vector<int> dp(n+1, 0);
        int offSet = 1;
        for(int i = 1; i<=n; i++){
            if(offSet*2 == i) offSet = 2*offSet;
            dp[i] = dp[i-offSet]+1;
        }
        
        return dp;
    }
    //T - O(n)
    //S - O(1) No auxillary space used
};