class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        
        int maxPrice = -1;
        
        for(int i = n-1; i>=0; i--){
            if(prices[i] > maxPrice)
                maxPrice = prices[i];
            else{
                res += maxPrice-prices[i];
                maxPrice = prices[i];
            }
        }
        
        return res;
    }
    //T - O(n)
    //S - O(1)
};