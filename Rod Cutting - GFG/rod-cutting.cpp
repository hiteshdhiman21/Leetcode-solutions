// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:

    
    int cutRod(int price[], int n) {
        /*Use DP to calculate optimal cutting for each length
        Step-1. set dp[0] = 0.
        Step-2. for each len, calculate optimal cutting dp[len] using optimal cutting for smaller parts. for each dp[part1] , dp[len-part1] 
                whichever gives the max sum, optimal cutting is those part1 and part2 for that len.
        Step-3. Finally return dp[n]*/
        
        vector<int> dp(n+1, 0);
        
        for(int len=1; len<=n; len++){
            dp[len] = price[len-1];
            for(int part1=1; part1 <=len-1; part1++){
                int part2 = len-part1;
                dp[len] = max(dp[len], dp[part1]+dp[part2]);
            }
        }
        
        return dp[n];
    }
    //T - O(n)
    //S - O(n)
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends