// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        
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
    }
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