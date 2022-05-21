class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //Used DP
        //dp[amnt] == INT_MAX denotes it is not possible to sum up to the given amnt using coins
        //for amnt in range(0, amount+1)
        //  for coin in coins
        //      if(amnt-coin >= 0 && dp[amnt-coin] != INT_MAX) dp[amnt] =min(dp[amnt], dp[amnt-coin]+1)
        
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for(int amnt = 1; amnt <= amount; amnt++){
            for(int coin: coins){
                if(amnt-coin >= 0 && dp[amnt-coin] != INT_MAX)
                    dp[amnt] = min(dp[amnt], dp[amnt-coin]+1);
            }
        }
        
        if(dp[amount] == INT_MAX) return -1;
        else return dp[amount];
        
        //T - amount*coins.size()
        //S - O(amount)
    }
};