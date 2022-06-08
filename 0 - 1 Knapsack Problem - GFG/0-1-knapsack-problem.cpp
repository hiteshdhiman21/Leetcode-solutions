// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    /*int knapSack(int W, int wt[], int val[], int n) 
    { 
        //Original dp
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
        for(int ind = n-1; ind>=0; ind--){
            for(int w = 0; w <= W; w++){
               //Not take
               if(ind+1 < n) dp[ind][w] = dp[ind+1][w];
               
               //Can take
               if(w-wt[ind] >= 0){
                   int take = val[ind];
                   if(ind+1 <n) take += dp[ind+1][w-wt[ind]];
                   dp[ind][w] = max(dp[ind][w], take);
               }
              
            }
        }
        
        return dp[0][W];
    }*/
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        //Optimised space dp
        /*Use only 1 array. Because dp[ind][w] depends on dp[ind+1][w] and dp[ind+1][w-wt[ind]] so dp[ind]
        values only depends upon dp[ind+1] values. i.e. why we only need dp[ind+1] array to construct dp[ind]
        So, we can do that using only 1 array. dp[w]ci = dp[w]pi and dp[w]ci = dp[w-wt[ind]] pi by iterating
        in decreasing value of weight.
        */
        
        vector<int> dp(W+1, 0);
        
        for(int ind = n-1; ind>=0; ind--){
            //Iterate in this direction
            for(int w = W; w >= 0; w--){
               //Not take
               if(ind+1 < n) dp[w] = dp[w];
               
               //Can take
               if(w-wt[ind] >= 0){
                   int take = val[ind];
                   if(ind+1 <n) take += dp[w-wt[ind]];
                   dp[w] = max(dp[w], take);
               }
              
            }
        }
        
        return dp[W];
    }
    //T - O(n*W)
    //S - O(n)
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends