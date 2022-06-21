class Solution {
public:
    int combinationSum4(vector<int>& coins, int amount) {
      /*Different sequences of same numbers are counter separately*/  
        vector<int> dp(amount+1);
        dp[0] = 1;
        
        
        for(int am = 1; am <= amount; am++){
            for(int coin: coins){
                if(am-coin >= 0)
                    dp[am] = min(dp[am]+(long)dp[am-coin], (long)INT_MAX);
            }
        }
        
        return dp[amount];
    }
    //T - O(totalCoins*amount)
    //S - O(amount)
    
};