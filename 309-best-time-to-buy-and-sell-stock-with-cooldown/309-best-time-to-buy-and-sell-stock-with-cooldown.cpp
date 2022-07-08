class Solution {
public:
    int maxProfit(vector<int>& prices) {      
        //Complex but very good problem
      /*Buy[i] denotes some stock is buyed on day <= i and what is max net profit after keeping some stock(Most profitable priced stock).
        Sell[i] denotes net profit after not keeping any stock on day i. It means not buying any stock on this day, if there is no kept stock or just                 selling the most profitable kept stock price on this day*/
        int n = prices.size();
        
        if(n<=1) return 0;
        
        vector<int> buy(n), sell(n);
        buy[0] = -prices[0];
        sell[0] = 0;
        buy[1] = max(-prices[1], -prices[0]);
        sell[1] = max(sell[0], buy[0]+prices[1]);
        
        for(int i=2; i<n; i++){
            buy[i] = max(sell[i-2]-prices[i], buy[i-1]);
            sell[i] = max(buy[i-1]+prices[i], sell[i-1]);
            cout << buy[i] << " " << sell[i] << endl;
        }
        
        return sell[n-1];
    }
    //T - O(n)
    //S - O(n) can be modified to O(1)
};
