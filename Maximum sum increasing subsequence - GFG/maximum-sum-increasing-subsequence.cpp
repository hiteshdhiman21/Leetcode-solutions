// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int nums[], int n)  
	{  
	    //dp[ind] will store the max Sum IS ending with index ind.
	  /*Step-1. First calculate dp[ind] for all indexes.
	    Step-2. A nums[ind] can only attach after some nums[prevInd] where prevInd < ind and nums[prevInd] < nums[ind]. So, to make max sum IS ending
	    at index ind, we will take prevInd such that dp[prevInd] > dp[all prevInd] and nums[prevInd] < nums[ind].
	    Step-3. Finally go through ever ind and return maximum dp[ind] among them because maxSumIS will also end at some ind.
	    */
	    vector<int> dp(n);
	    int maxSum = 0;
	    for(int ind = 0; ind < n; ind++){
	        dp[ind] = nums[ind];
	        for(int prevInd = ind-1; prevInd >=0; prevInd--){
	            if(nums[prevInd] < nums[ind])
	                dp[ind] = max(dp[ind], dp[prevInd]+nums[ind]);
	        } 
	        
	        maxSum = max(maxSum, dp[ind]);
	    }
	    
	    return maxSum;
	}  
	//T - O(n^2)
	//S - O(N)
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends