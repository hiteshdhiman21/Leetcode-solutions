class Solution {
public:

    
    int maxCoins(vector<int>& nums) {
      /*Intuition: If we try some i to be first stone in [s,e], then subproblems for [s,i-1] and [i+1, e] are inter-related and so we can't call recursion separately for both paritions.
        Instead, We will travel opposite in time and try to find ans. We can think it this way. Stones[s, e] are bursted except one and all the stones before s i.e, [, s-1] and after e i.e, [e+1, ] will be bursted in future. And so it means, currently those [, s-1] and [e+1, ] are present. And out of [s, e], we need to find which will be bursted last and all others have been bursted before(after in reverse time traversing). And so suppose if out of [s, e] we will burst some b now(it means last), it will have its neighbour as (s-1) and (e+1) as they will be bursted after it (before in reverse time traversing) and not in [s,e] as they will be bursted before(after in reverse time traversing). 
        */
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int len=1; len<=n; len++){
            for(int s=0; s<=n-len; s++){
                
                int e=s+len-1;
                
                int res = 0;
                for(int b = s; b<=e; b++){
                    int score = nums[b];
                    if(s!=0) score *= nums[s-1];
                    if(e!=n-1) score *= nums[e+1];
                    
                    if(b-1 >= s)
                    score += dp[s][b-1]; //dp[s][b-1] will definitely be using b
                    
                    if(b+1 <= e)
                    score += dp[b+1][e];  //dp[b+1][e] will definitely be using b
                    
                    res = max(res, score);
                }
                
                dp[s][e] = res;
            
            }
        }
        
        return dp[0][n-1];        
    }
    //T - O(n*n*n)
    //S - O(n*n)
};